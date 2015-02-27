/* -*- Mode: C; c-basic-offset: 4; indent-tabs-mode: nil -*- */
/*
   Copyright (C) 2010 Red Hat, Inc.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/
#include "spice-client.h"
#include "spice-common.h"
#include "spice-channel-priv.h"

#include "channel-display-priv.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#if 0
static void pgm_save_one_file(uint8_t **data, int *linesize, int xsize, int ysize)
{
	int fd = -1;
	fd = open("/data/dump.yuv", O_RDWR | O_CREAT | O_TRUNC, 0777);

	int i;
	for (i = 0; i < ysize; i++)
		write(fd, data[0] + i * linesize[0], xsize); 

	for (i = 0; i < ysize / 2; i++)
		write(fd, data[1] + i * linesize[1], xsize / 2); 

	for (i = 0; i < ysize / 2; i++)
		write(fd, data[2] + i * linesize[2], xsize / 2); 

	close(fd);
}
#endif

static int decode_packet(display_stream *st, int width, int height)
{
    int ret = 0, got_frame = 0;

    ret = avcodec_decode_video2(st->context, st->frame, &got_frame, &st->packet);
    if (ret < 0) {
        fprintf(stderr, "Error decoding video frame (%s)\n", av_err2str(ret));
        return ret;
    }

	if(st->sws_ctx == NULL) {
		fprintf(stderr, "new stream. reinit sws\n");

		st->buffer = (uint8_t *)av_malloc(st->frame->linesize[0] * height * 4);
		st->dst_data[0] = st->buffer;
		st->dst_data[1] = NULL;
		st->dst_data[2] = NULL;
		st->dst_data[3] = NULL;

		st->sws_ctx = sws_getContext(
				st->frame->linesize[0],
				height, 
				PIX_FMT_YUV420P,
				st->frame->linesize[0],
				height, 
				PIX_FMT_RGBA, 
				SWS_BICUBIC, NULL, NULL, NULL);

		av_image_fill_linesizes(st->dst_linesize, PIX_FMT_RGBA, st->frame->linesize[0]);
	}

	if (got_frame) {
		sws_scale(st->sws_ctx, 
				(const uint8_t * const*)st->frame->data, st->frame->linesize, 0, height,
				st->dst_data, st->dst_linesize);

		uint8_t *pp = st->dst_data[0];
		int  j = 0;
		for(j = 0; j < height; j++) {
			memcpy(st->out_frame + j * width * 4, pp + j * st->frame->linesize[0] * 4, width * 4);
		}
	}

	return 0;
}

G_GNUC_INTERNAL
void stream_h264_new(display_stream *st)
{
	av_register_all();

	av_init_packet(&st->packet);

	if (!(st->pcodec = avcodec_find_decoder(CODEC_ID_H264))) {
		fprintf(stderr, "pcodec not found!");
		return ;
	}

	st->context = avcodec_alloc_context3(st->pcodec);

	st->frame = avcodec_alloc_frame();	

	if (avcodec_open2(st->context, st->pcodec, &st->optionsDict) < 0) {
		fprintf(stderr, "could not open pcodec!\n");
		return ;
	}

	st->optionsDict =	NULL;
	st->sws_ctx =		NULL;
	st->buffer =		NULL;

	st->rgba_buf = NULL;
}

G_GNUC_INTERNAL
void stream_h264_cleanup(display_stream *st)
{
	stream_h264_finit(st);
	av_free(st->frame);
	avcodec_close(st->context);
}

G_GNUC_INTERNAL
void stream_h264_init(display_stream *st)
{
	st->sws_ctx = NULL;
}

G_GNUC_INTERNAL
void stream_h264_finit(display_stream *st)
{
	if(st->buffer != NULL) {
		av_free(st->buffer);
		st->buffer = NULL;	
	}

	if(st->sws_ctx != NULL) {
		sws_freeContext(st->sws_ctx);
		st->sws_ctx = NULL;
	}

	if(st->rgba_buf != NULL) {
		free(st->rgba_buf);
		st->rgba_buf = NULL;
	}
}


G_GNUC_INTERNAL
void stream_h264_data(display_stream *st)
{
	int width, height;
	uint8_t *data;
	int size = stream_get_current_frame(st, &data);

	stream_get_dimensions(st, &width, &height);

	if(st->stream_width != width || st->stream_height != height) {
		st->stream_width = width;
		st->stream_height = height;

		stream_h264_finit(st);
		stream_h264_init(st);	

		st->rgba_buf = g_malloc0(st->stream_width * st->stream_height * 4);
	}

	st->out_frame = st->rgba_buf;

	av_init_packet(&st->packet);
	st->packet.data = data;
	st->packet.size = size;
	decode_packet(st, width, height);
	av_free_packet(&st->packet);
}
