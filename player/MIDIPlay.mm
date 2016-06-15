//
//  MIDIPlay.m
//  midipipe
//
//  Created by Christopher Snowhill on 6/14/16.
//  Copyright © 2016 Christopher Snowhill. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MIDIPlay.h"

#import "MIDIPlayer.h"
#import "AUPlayer.h"
#import "BMPlayer.h"
#import "MSPlayer.h"
#import "SCPlayer.h"

void * mp_create(int driver)
{
    void * handle = NULL;
    MIDIPlayer * mp = NULL;
    
    switch (driver)
    {
        default:
        case 0:
            mp = new BMPlayer;
            break;
            
        case 1:
            mp = new AUPlayer;
            break;
            
        case 2:
            mp = new MSPlayer;
            break;
            
        case 3:
            mp = new SCPlayer;
            ((SCPlayer *)mp)->set_sccore_path("/Library/Audio/Plug-Ins/Components/SOUND Canvas VA.component/Contents/Resources/SCCore00.dylib");
            break;
    }
    
    if (mp) handle = (void *) mp;
    
    return handle;
}

void mp_delete(void *mp)
{
    MIDIPlayer * m = (MIDIPlayer *) mp;
    delete m;
}

void mp_set_rate(void *mp, uint32_t sample_rate)
{
    MIDIPlayer * m = (MIDIPlayer *) mp;
    m->setSampleRate(sample_rate);
}

void mp_set_soundfont(void *mp, const char *path)
{
    MIDIPlayer * m = (MIDIPlayer *) mp;
    m->setSoundFont(path);
}

void mp_set_preset(void *mp, uint32_t preset)
{
    MIDIPlayer * m = (MIDIPlayer *) mp;
    m->setPreset(preset);
}

void mp_render(void *mp, float *out, size_t count)
{
    MIDIPlayer * m = (MIDIPlayer *) mp;
    m->Play(out, count);
}

void mp_send_short(void *mp, uint32_t e)
{
    MIDIPlayer * m = (MIDIPlayer *) mp;
    m->send_short(e);
}

void mp_send_long(void *mp, const uint8_t *e, size_t length)
{
    MIDIPlayer * m = (MIDIPlayer *) mp;
    m->send_long(e, length);
}
