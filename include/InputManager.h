//
//  InputManager.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

using namespace std;

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

#include "../include/SDL_include.h"
#include <iostream>
#include <unordered_map>

class InputManager{
    
public:
    void Update();
    bool KeyPress(int key);
    bool KeyRelease(int key);
    bool IsKeyDown(int key);
    
    bool MousePress(int button);
    bool MouseRelease(int button);
    bool IsMouseDown(int button);
    
    int GetMouseX();
    int GetMouseY();
    
    bool QuitRequested();
    
    static InputManager& GetInstance();
    
private:
    InputManager();
    ~InputManager();
    
    bool mouseState[6];
    int mouseUpdate[6];
    
    unordered_map<int, bool> keyState;
    unordered_map<int, int> keyUpdate;
    
    bool quitRequested;
    int updateCounter;
    
    int mouseX;
    int mouseY;
    
};
