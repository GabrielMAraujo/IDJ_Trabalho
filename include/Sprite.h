//
//  Sprite.h
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
#include "../include/SDL_include.h"
#include "../include/Component.h"
#include "../include/Resources.h"

using namespace std;

//class GameObject;

class Sprite : public Component{
    
public:
    Sprite(GameObject& associated);
    Sprite( GameObject& associated, string file);
    ~Sprite();
    void Open(string file);
    void SetClip(int x, int y, int w, int h);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    void Update(float dt);
    void Render();
    void Render(int x, int y);
    bool Is(string type);
    
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
    
};
