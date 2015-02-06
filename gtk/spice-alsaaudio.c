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
	uint32_t bits_per_sample = 16;;
	uint32_t channels = 2;
	uint32_t signed_or_not = 1;

	const int frame_size = FRAME_SIZE;
	const char* pcm_device = "default";

	snd_pcm_format_t format;
	format = SND_PCM_FORMAT_S16_LE;

	int _sampels_per_ms = sampels_per_sec / 1000;
	if ((err = snd_pcm_open(&_pcm, pcm_device, SND_PCM_STREAM_PLAYBACK, SND_PCM_ASYNC)) < 0) {
	//if ((err = snd_pcm_open(&_pcm, pcm_device, SND_PCM_STREAM_PLAYBACK, SND_PCM_NONBLOCK)) < 0) {
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

#if 0
int read_exact(int sock, char *buf, int size)
{
	int count = 0;
	int tmp;

	while(count < size)
	{
		tmp = read(sock, buf + count, size - count);
		if(tmp >= 0)
			count += tmp;
		else 
			return -1;
	}

	return 0;
}

int main(int argc, char *argv[])
{

	alsa_init();

	int client_sockfd;
	int len;
	struct sockaddr_in remote_addr; 
	memset(&remote_addr,0,sizeof(remote_addr)); 
	remote_addr.sin_family=AF_INET; 
	remote_addr.sin_addr.s_addr=inet_addr("10.3.2.58");
	remote_addr.sin_port=htons(12306); 

	if((client_sockfd=socket(PF_INET,SOCK_STREAM,0))<0)
	{
		perror("socket");
		return 1;
	}


	if(connect(client_sockfd,(struct sockaddr *)&remote_addr,sizeof(struct sockaddr))<0)
	{
		perror("connect");
		return 1;
	}

	fprintf(stderr, "connect ok ! \n");

	uint8_t buf[1792];
	int ret = 0;

	while(1) {
		ret = read_exact(client_sockfd, buf, 1792);
		if(ret < 0)
			break;

		alsa_playback((uint32_t *)buf, 448);
	}

	close(client_sockfd);

	alsa_finit();
	return 0;
}
#endif
