//
//  State.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 15/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//
#pragma once

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL

#include <iostream>
#include "SDL_include.h"
#include "Sprite.h"
#include "Music.h"

using namespace std;

class State{
    
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
    
private:
    Sprite bg;
    Music music;
    bool quitRequested;
    
};
