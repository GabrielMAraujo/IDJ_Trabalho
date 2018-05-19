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
#define INCLUDE_SDL_TTF

#include <iostream>
#include <stack>

#include "../include/SDL_include.h"
#include "../include/State.h"
#include "../include/StageState.h"
#include "../include/InputManager.h"

using namespace std;

class Game{
    
private:
    //Variáveis
    static Game* instance;
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* storedState;
    int frameStart;
    float dt;
    stack<unique_ptr<State>> stateStack;
    
    
    //Funções
    void CalculateDeltaTime();
    
public:
    //Funções
    void Run();
    SDL_Renderer *GetRenderer();
    State& GetCurrentState();
    static Game& GetInstance();
    Game(string title, int width, int height);
    ~Game();
    float GetDeltaTime();
    void Push(State* state);
    void AddEndState();
    
};
