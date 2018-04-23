//
//  Game.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//
#pragma once

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL

#include <iostream>
#include "../include/SDL_include.h"
#include "../include/State.h"
#include "../include/InputManager.h"

using namespace std;

class Game{
    
private:
    //Variáveis
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
    int frameStart;
    float dt;
    void CalculateDeltaTime();
    
    //Funções
    
    Game(string title, int width, int height);
    
public:
    //Funções
    void Run();
    SDL_Renderer *GetRenderer();
    State& GetState();
    static Game& GetInstance();
    ~Game();
    float GetDeltaTime();
};
