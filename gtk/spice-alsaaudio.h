#ifndef __SPICE_CLIENT_ALSAAUDIO_H__
#define __SPICE_CLIENT_ALSAAUDIO_H__


int alsa_init(void);
int alsa_finit(void);
int alsa_playback(uint32_t *frame, int size);
int alsa_set_volume(long left_vol, long right_vol);
#endif
