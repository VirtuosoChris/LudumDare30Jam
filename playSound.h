//
//  playSound.h
//  TileTest
//
//  Created by Admin on 8/23/14.
//  Copyright (c) 2014 Admin. All rights reserved.
//

#ifndef TileTest_playSound_h
#define TileTest_playSound_h

#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#include <AL/alut.h>

inline void playSound(const std::string& sound){
    
    static bool hasInit = false;
    
	ALuint buffer = alutCreateBufferFromFile(sound.c_str());
    
	if(!buffer)throw std::runtime_error((std::string("could not find sound file ") + sound));
    
    ALuint source;
    alGenSources(1, &source);
	alSourcei(source, AL_BUFFER,buffer);
	alSourcePlay(source);
    
}


#endif
