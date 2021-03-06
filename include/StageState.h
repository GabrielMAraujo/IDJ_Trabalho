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

//#define PI 3.14159265

#include <iostream>
#include <memory>
#include <vector>
#include "../include/SDL_include.h"
#include "../include/Sprite.h"
#include "../include/Music.h"
#include "../include/Vec2.h"
#include "../include/Math.h"
#include "../include/Face.h"
#include "../include/TileMap.h"
#include "../include/Camera.h"
#include "../include/CameraFollower.h"
#include "../include/Alien.h"
#include "../include/PenguinBody.h"
#include "../include/Collision.h"

using namespace std;

class State{
    
public:
    State();
    ~State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
    void Start();
    void AddObject(GameObject* go);
    
private:
    Music music;
    bool quitRequested;
    vector<unique_ptr<GameObject>> objectArray;
    bool started;
    
    void Input();
    void AddObject(int mouseX, int mouseY);
};
