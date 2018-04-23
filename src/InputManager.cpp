//
//  InputManager.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/InputManager.h"

InputManager::InputManager(){
    updateCounter = 0;
    quitRequested = false;
    mouseX = 0;
    mouseY = 0;
    
    for(int x = 0; x < 6; x++){
        mouseState[x] = 0;
        mouseUpdate[x] = 0;
    }
}

InputManager::~InputManager(){
    
}


void InputManager::Update(){
    
    SDL_GetMouseState(&mouseX, &mouseY);
    
    updateCounter++;
    
    quitRequested = false;
    
    SDL_Event evento;
    
    while(SDL_PollEvent(&evento)){
        
        
        if(evento.type == SDL_QUIT){
            quitRequested = true;
        }
        
        if(evento.type == SDL_MOUSEBUTTONDOWN){
            mouseState[evento.button.button] = true;
            mouseUpdate[evento.button.button] = updateCounter;
        }
        
        if(evento.type == SDL_MOUSEBUTTONUP){
            mouseState[evento.button.button] = false;
            mouseUpdate[evento.button.button] = updateCounter;
        }
    
        if(!evento.key.repeat){
        
            if(evento.type == SDL_KEYUP){
//                cout << "key up" << endl;
                keyState[evento.key.keysym.sym] = false;
                keyUpdate[evento.key.keysym.sym] = updateCounter;
            }
            
            if(evento.type == SDL_KEYDOWN){
//                cout << "key down" << endl;
                keyState[evento.key.keysym.sym] = true;
                keyUpdate[evento.key.keysym.sym] = updateCounter;
            }
        
        }
    }
}

bool InputManager::KeyPress(int key){
//    cout <<keyUpdate[key] << endl;
    if(keyUpdate[key] == updateCounter){
        return keyState[key];
    }
    else{
        return false;
    }
}

bool InputManager:: KeyRelease(int key){
    if(keyUpdate[key] == updateCounter){
        return !keyState[key];
    }
    else{
        return false;
    }
}

bool InputManager::IsKeyDown(int key){
    return keyState[key];
}

bool InputManager::MousePress(int button){
    if(mouseUpdate[button] == updateCounter){
        return mouseState[button];
    }
    else{
        return false;
    }
}

bool InputManager::MouseRelease(int button){
    
    if(mouseUpdate[button] == updateCounter){
        return !mouseState[button];
    }
    else{
        return false;
    }
    
}

bool InputManager::IsMouseDown(int button){
    return mouseState[button];
}

int InputManager::GetMouseX(){
    return mouseX;
}

int InputManager::GetMouseY(){
    return mouseY;
}

bool InputManager::QuitRequested(){
    return quitRequested;
}

InputManager& InputManager::GetInstance(){
    static InputManager im;
    return im;
}
