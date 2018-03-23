//
//  Music.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL

#include <iostream>
#include "SDL_include.h"
using namespace std;

class Music{
    
public:
    Music();
    ~Music();
    Music(string file);
    void Play(int times);
    void Stop(int msToStop);
    void Open(string file);
    bool IsOpen();
    
private:
    Mix_Music *music;
    
};
