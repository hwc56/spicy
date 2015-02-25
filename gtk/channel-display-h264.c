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


static int decode_packet(display_stream *st, int *got_frame, int width, int height)
{
    int ret = 0;
    int decoded = st->packet.size;

    *got_frame = 0;

    ret = avcodec_decode_video2(st->context, st->frame, got_frame, &st->packet);
    if (ret < 0) {
        fprintf(stderr, "Error decoding video frame (%s)\n", av_err2str(ret));
        return ret;
    }

	static int flag = -1;
	if(flag == -1) {
		pgm_save_one_file(st->frame->data, st->frame->linesize, st->frame->linesize[0], height);
		flag = 1;
	}

	fprintf(stderr, "%d\n",st->frame->linesize[0]);

	if(st->sws_ctx == NULL) {
		st->sws_ctx = sws_getContext(
				st->frame->linesize[0],
				height + height % 2, 
				PIX_FMT_YUV420P,
				st->frame->linesize[0],
				height + height % 2, 
				PIX_FMT_RGBA, 
				SWS_BICUBIC, NULL, NULL, NULL);

		av_image_fill_linesizes(st->dst_linesize, PIX_FMT_RGBA, st->frame->linesize[0]);
	}

	if (*got_frame) {
		sws_scale(st->sws_ctx, 
				(const uint8_t * const*)st->frame->data, st->frame->linesize, 0, height + height % 2, 
				st->dst_data,
				st->dst_linesize);

		uint8_t *pp = st->dst_data[0];
		int  j = 0;
		for(j = 0; j < height; j++) {
			memcpy(st->out_frame + j * width * 4, pp + j * st->frame->linesize[0] * 4, width * 4);
		}
	}

    return decoded;
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

	st->rgba_buf = g_malloc0(1920 * 1080 * 4);
}

G_GNUC_INTERNAL
void stream_h264_cleanup(display_stream *st)
{
	stream_h264_finit(st);
	av_free(st->frame);
	avcodec_close(st->context);

	if(st->rgba_buf != NULL)
		free(st->rgba_buf);
}

G_GNUC_INTERNAL
void stream_h264_init(display_stream *st)
{
	int pad_width = st->stream_width;
	int pad_height = st->stream_height;

	pad_width += (16 - pad_width % 16);
	pad_height += pad_height % 2;

	//av_image_fill_linesizes(st->dst_linesize, PIX_FMT_RGBA, st->stream_width);

	st->buffer = (uint8_t *)av_malloc(1920 * 1080 * 4 * sizeof(uint8_t));
#if 0
	st->sws_ctx = sws_getContext(
			pad_width,
			pad_height, 
			PIX_FMT_YUV420P,
			st->stream_width,
			st->stream_height,
			PIX_FMT_RGBA, 
			SWS_BICUBIC,
			NULL,
			NULL,
			NULL);
#endif
	st->dst_data[0] = st->buffer;
	st->dst_data[1] = NULL;
	st->dst_data[2] = NULL;
	st->dst_data[3] = NULL;

	fprintf(stderr, "%d, %d\n", pad_width, pad_height);
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
}


G_GNUC_INTERNAL
void stream_h264_data(display_stream *st)
{
	int got_frame = 0;
	int width, height;
	uint8_t *data;
	int size = stream_get_current_frame(st, &data);

	stream_get_dimensions(st, &width, &height);

	st->out_frame = st->rgba_buf;

	if(st->stream_width != width || st->stream_height != height) {
		st->stream_width = width;
		st->stream_height = height;

		stream_h264_finit(st);
		stream_h264_init(st);	
	}

	static int fd = -1;
	if(fd == -1) {
		fd = open("/data/dump.h264", O_RDWR | O_CREAT | O_TRUNC, 0777);
		write(fd, data, size);
	}

	av_init_packet(&st->packet);
	st->packet.data = data;
	st->packet.size = size;
	decode_packet(st, &got_frame, width, height);
	av_free_packet(&st->packet);
}
