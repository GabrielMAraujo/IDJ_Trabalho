//
//  PenguinCannon.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 10/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/PenguinCannon.h"
#include "../include/Game.h"

Timer* timer;

PenguinCannon::PenguinCannon(GameObject& associated, GameObject& penguinBody) : Component(associated){
    
    Sprite* sp = new Sprite(associated, "assets/img/cubngun.png");
    associated.AddComponent(sp);
    
    Collider* c = new Collider(associated);
    associated.AddComponent(c);
    
    timer = new Timer(associated);
    associated.AddComponent(timer);
    
    pbody = &penguinBody;
    angle = 0;
}

void PenguinCannon::Start(){
    
}

void PenguinCannon::Update(float dt){
    if(pbody == nullptr){
        associated.RequestDelete();
    }
    
    associated.box.x = pbody->box.x;
    associated.box.y = pbody->box.y;
    
    associated.angleDeg = (Math::Vec2LineInclinationX(Vec2(associated.box.x + (associated.box.w/2), associated.box.y + (associated.box.h/2)), Vec2(InputManager::GetInstance().GetMouseX() + Camera::pos.x, InputManager::GetInstance().GetMouseY() + Camera::pos.y))) * (180 / PI);
    
    if(InputManager::GetInstance().MousePress(SDL_BUTTON_LEFT)){
        Shoot();
    }
    
}

void PenguinCannon::Render(){
    
}

bool PenguinCannon::Is(string type){
    if(type == "PenguinCannon"){
        return true;
    }
    else{
        return false;
    }
}

void PenguinCannon::Shoot(){
    
    if(timer->Get() >= COOLDOWN){
        
        timer->Restart();
    
        GameObject* goBullet = new GameObject();
        
        goBullet->box.x =associated.box.x + (associated.box.w/2) + associated.box.w/2 * cos(associated.angleDeg * PI / 180);
        goBullet->box.y =associated.box.y + (associated.box.h/2) + associated.box.h/2 * sin(associated.angleDeg * PI / 180);
        
        Bullet* b = new Bullet(*goBullet, associated.angleDeg * (PI / 180) , 500, 10, 500, "assets/img/penguinbullet.png", 4, 0.2, false);
        goBullet->AddComponent(b);
        Game::GetInstance().GetCurrentState().AddObject(goBullet);
        
    }
}
       

       
       
