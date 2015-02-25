#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <asoundlib.h>
#include <stdbool.h>

#define FRAME_SIZE 256

static snd_pcm_t *_pcm;
static snd_pcm_hw_params_t *_hw_params;
static snd_pcm_sw_params_t *_sw_params;

int alsa_init(void)
{
	int err;
	uint32_t sampels_per_sec = 44100; 
	uint32_t channels = 2;

	const int frame_size = FRAME_SIZE;
	const char* pcm_device = "default";

	snd_pcm_format_t format;
	format = SND_PCM_FORMAT_S16_LE;

	//if ((err = snd_pcm_open(&_pcm, pcm_device, SND_PCM_STREAM_PLAYBACK, SND_PCM_ASYNC)) < 0) {
	if ((err = snd_pcm_open(&_pcm, pcm_device, SND_PCM_STREAM_PLAYBACK, SND_PCM_NONBLOCK)) < 0) {
		printf("cannot open audio playback device %s %s", pcm_device, snd_strerror(err));
		return false;
	}

	if ((err = snd_pcm_hw_params_malloc(&_hw_params)) < 0) {
		printf("cannot allocate hardware parameter structure %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_sw_params_malloc(&_sw_params)) < 0) {
		printf("cannot allocate software parameter structure %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_hw_params_any(_pcm, _hw_params)) < 0) {
		printf("cannot initialize hardware parameter structure %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_hw_params_set_access(_pcm, _hw_params,
					SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
		printf("cannot set access type %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_hw_params_set_rate(_pcm, _hw_params, sampels_per_sec, 0)) < 0) {
		printf("cannot set sample rate %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_hw_params_set_channels(_pcm, _hw_params, channels)) < 0) {
		printf("cannot set channel count %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_hw_params_set_format(_pcm, _hw_params, format)) < 0) {
		printf("cannot set sample format %s", snd_strerror(err));
		return false;
	}

	snd_pcm_uframes_t buffer_size;
	buffer_size = (sampels_per_sec * 300 / 1000) / frame_size * frame_size;
	if ((err = snd_pcm_hw_params_set_buffer_size_near(_pcm, _hw_params, &buffer_size)) < 0) {
		printf("cannot set buffer size %s", snd_strerror(err));
		return false;
	}

	int direction = 1;
	snd_pcm_uframes_t period_size = (sampels_per_sec * 20 / 1000) / frame_size * frame_size;
	if ((err = snd_pcm_hw_params_set_period_size_near(_pcm, _hw_params, &period_size,
					&direction)) < 0) {
		printf("cannot set period size %s", snd_strerror(err));
		return false;
	}

	if ((err = snd_pcm_hw_params(_pcm, _hw_params)) < 0) {
		printf("cannot set parameters %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_sw_params_current(_pcm, _sw_params)) < 0) {
		printf("cannot obtain sw parameters %s", snd_strerror(err));
		return false;
	}
	err = snd_pcm_hw_params_get_buffer_size(_hw_params, &buffer_size);
	if (err < 0) {
		printf("unable to get buffer size for playback: %s", snd_strerror(err));
		return false;
	}
	direction = 0;
	err = snd_pcm_hw_params_get_period_size(_hw_params, &period_size, &direction);
	if (err < 0) {
		printf("unable to get period size for playback: %s", snd_strerror(err));
		return false;
	}

	err = snd_pcm_sw_params_set_start_threshold(_pcm, _sw_params,
			(buffer_size / period_size) * period_size);

	if (err < 0) {
		printf("unable to set start threshold mode for playback: %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_sw_params(_pcm, _sw_params)) < 0) {
		printf("cannot set software parameters %s", snd_strerror(err));
		return false;
	}
	if ((err = snd_pcm_prepare(_pcm)) < 0) {
		printf("cannot prepare pcm device %s", snd_strerror(err));
		return false;
	}

	return true;
}

int alsa_finit(void)
{
	snd_pcm_close(_pcm);
	snd_pcm_hw_params_free(_hw_params);
	snd_pcm_sw_params_free(_sw_params);

	_pcm = NULL;
	_hw_params = NULL;
	_sw_params = NULL;

	return 0;
}

int alsa_playback(uint32_t *frame, int size)
{
	snd_pcm_sframes_t ret = snd_pcm_writei(_pcm, frame, size);
	if (ret < 0) {
		if (ret == -EAGAIN) {
			return false;
		}
		if (snd_pcm_recover(_pcm, ret, 1) == 0) {
			snd_pcm_writei(_pcm, frame, FRAME_SIZE);
		}
		snd_pcm_prepare(_pcm);
	}
	return true;
}

void alsa_set_volume(long left_vol, long right_vol)
{
    long min, max;
    snd_mixer_t* handle;
    snd_mixer_selem_id_t* sid;
    const char* card = "default";
    const char* selem_name = "Master";

    snd_mixer_open(&handle, 0); 
    snd_mixer_attach(handle, card);
    snd_mixer_selem_register(handle, NULL, NULL);
    snd_mixer_load(handle);

    snd_mixer_selem_id_alloca(&sid);
    snd_mixer_selem_id_set_index(sid, 0); 
    snd_mixer_selem_id_set_name(sid, selem_name);
    snd_mixer_elem_t* elem = snd_mixer_find_selem(handle, sid);

    snd_mixer_selem_get_playback_volume_range(elem, &min, &max);
    snd_mixer_selem_set_playback_volume(elem,SND_MIXER_SCHN_REAR_LEFT, left_vol);
    snd_mixer_selem_set_playback_volume(elem,SND_MIXER_SCHN_SIDE_LEFT, left_vol);
    snd_mixer_selem_set_playback_volume(elem,SND_MIXER_SCHN_FRONT_LEFT, left_vol);

    snd_mixer_selem_set_playback_volume(elem,SND_MIXER_SCHN_REAR_RIGHT, right_vol);
    snd_mixer_selem_set_playback_volume(elem,SND_MIXER_SCHN_SIDE_RIGHT, right_vol);
    snd_mixer_selem_set_playback_volume(elem,SND_MIXER_SCHN_FRONT_RIGHT, right_vol);

    snd_mixer_close(handle);
}
