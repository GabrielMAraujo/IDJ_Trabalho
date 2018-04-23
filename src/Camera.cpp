//
//  Camera.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 20/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Camera.h"

Vec2 Camera::pos(0,0);
Vec2 Camera::speed(100,100);
GameObject* Camera::focus = nullptr;

void Camera::Follow(GameObject* newFocus){
    focus = newFocus;
}

void Camera::Unfollow(){
    focus = nullptr;
}

void Camera::Update(float dt){
    if(focus != nullptr){
        pos.x = focus->box.x - 512; //512 = largura da tela / 2
        pos.y = focus->box.y - 300; //300 = altura da tela / 2
    }
    else{
        if(InputManager::GetInstance().IsKeyDown(SDLK_w)){
            pos.y -= speed.y * dt;
        }
        
        if(InputManager::GetInstance().IsKeyDown(SDLK_s)){
            pos.y += speed.y * dt;
        }
        
        if(InputManager::GetInstance().IsKeyDown(SDLK_a)){
            pos.x -= speed.x * dt;
        }
        
        if(InputManager::GetInstance().IsKeyDown(SDLK_d)){
            pos.x += speed.x * dt;
        }
    }
}
