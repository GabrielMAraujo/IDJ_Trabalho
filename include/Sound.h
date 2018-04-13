//
//  Sound.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE

#include "../include/SDL_include.h"
#include "../include/GameObject.h"
#include <vector>

using namespace std;

class Sound: public Component{
    
public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, string file);
    ~Sound();
    void Play(int times = 1);
    void Stop();
    void Open(string file);
    bool IsOpen();
    bool IsPlaying();
    
    void Update(float dt);
    void Render();
    bool Is(string type);
    
private:
    Mix_Chunk* chunk;
    int channel;
    
};
