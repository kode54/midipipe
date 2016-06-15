//
//  MIDIPlay.h
//  midipipe
//
//  Created by Christopher Snowhill on 6/14/16.
//  Copyright © 2016 Christopher Snowhill. All rights reserved.
//

#ifndef MIDIPlay_h
#define MIDIPlay_h

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
    
int mp_safe();

void * mp_create(int driver);
void mp_delete(void *mp);

void mp_set_rate(void *mp, uint32_t sample_rate);

void mp_set_soundfont(void *mp, const char *path);

void mp_set_preset(void *mp, uint32_t preset);

void mp_render(void *mp, float *out, size_t count);

void mp_send_short(void *mp, uint32_t e);
void mp_send_long(void *mp, const uint8_t *e, size_t length);

#ifdef __cplusplus
}
#endif

#endif /* MIDIPlay_h */
