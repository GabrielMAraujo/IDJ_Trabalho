//
//  Face.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 06/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/Face.h"

Face::Face(GameObject& associated) : Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    cout << "Dano: " << hitpoints;
    if(hitpoints <= 0){
        associated.RequestDelete();
        ((Sound*)associated.GetComponent("Sound"))->Play();
        
        Sprite *s = (Sprite*) associated.GetComponent("Sprite");
        if(s){
            associated.RemoveComponent(s);
        }
        associated.RemoveComponent(this);
    }
}

void Face::Update(float dt){
    if(InputManager::GetInstance().MousePress(LEFT_MOUSE_BUTTON)){
        int mouseX = InputManager::GetInstance().GetMouseX() + Camera::pos.x;
        int mouseY = InputManager::GetInstance().GetMouseY() + Camera::pos.y;
        if(Math::RectContains(associated.box, Vec2((float)mouseX, (float)mouseY))){
            Damage(std::rand() % 10 + 10);
        }
    }
}

void Face::Render(){
    ((Sprite*)associated.GetComponent("Sprite"))->Render(associated.box.x - Camera::pos.x, associated.box.y - Camera::pos.y);
}

bool Face::Is(string type){
    if(type == "Face"){
        return true;
    }
    else{
        return false;
    }
}
