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

static int decode_packet(display_stream *st, int *got_frame, int cached, 
		int width, int height, int width_h264, int height_h264)
{
    int ret = 0;
    int decoded = st->packet.size;

    *got_frame = 0;

    /* decode video frame */
    ret = avcodec_decode_video2(st->context, st->frame, got_frame, &st->packet);
    if (ret < 0) {
        fprintf(stderr, "Error decoding video frame (%s)\n", av_err2str(ret));
        return ret;
    }

    if (*got_frame) {
        /* copy decoded frame to destination buffer:
        * this is required since rawvideo expects non aligned data */
		//flip the picture 
		st->frame->data[0] += st->frame->linesize[0] * (st->context->height - 1);    
		st->frame->linesize[0] *= -1;    
		st->frame->data[1] += st->frame->linesize[1] * (st->context->height / 2 - 1);    
		st->frame->linesize[1] *= -1;    
		st->frame->data[2] += st->frame->linesize[2] * (st->context->height / 2 - 1);    
		st->frame->linesize[2] *= -1;  

		sws_scale(
				st->sws_ctx, 
				(uint8_t const * const *)st->frame->data,
				st->frame->linesize,
				0,
				st->context->height,
				st->pFrameRGB->data,
				st->pFrameRGB->linesize);

		int i;
		int stride = width * 4;
		int stride_h264 = width_h264 * 4;
		uint8_t *pp = st->pFrameRGB->data[0];
		for (i = 0; i < height; i++) {
            memcpy(st->out_frame + i*stride, pp + i*stride_h264, stride);
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
	st->pFrameRGB =		NULL;
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
	int pad_width = st->stream_width;
	int pad_height = st->stream_height;

	pad_width += pad_width % 2;
	pad_height += pad_height % 2;

	st->pFrameRGB = avcodec_alloc_frame();
	if (st->pFrameRGB == NULL)
		return ;

	st->buffer = (uint8_t *)av_malloc(pad_width * pad_height * 4 * sizeof(uint8_t));
	st->sws_ctx = sws_getContext(
			pad_width, 
			pad_height, 
			PIX_FMT_YUV420P,
			pad_width, 
			pad_height,
			PIX_FMT_RGBA, 
			SWS_BILINEAR,
			NULL, 
			NULL, 
			NULL);

	avpicture_fill(
			(AVPicture *)st->pFrameRGB, 
			st->buffer, 
			PIX_FMT_BGRA, 
			pad_width, 
			pad_height);
}

G_GNUC_INTERNAL
void stream_h264_finit(display_stream *st)
{
	if(st->pFrameRGB != NULL) {
		av_free(st->pFrameRGB);
		st->pFrameRGB = NULL;
	}

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
	uint8_t *dest;
	int size = stream_get_current_frame(st, &data);

	stream_get_dimensions(st, &width, &height);
	dest = g_malloc0(width * height * 4);

	g_free(st->out_frame);
	st->out_frame = dest;

	if(st->stream_width != width || st->stream_height != height) {
		st->stream_width = width;
		st->stream_height = height;

		stream_h264_finit(st);
		stream_h264_init(st);	
	}

	st->packet.data = data;
	st->packet.size = size;

	AVPacket orig_pkt = st->packet;
	decode_packet(st, &got_frame, 0, width, height, width + width % 2, height + height % 2);

	av_free_packet(&orig_pkt);
}
