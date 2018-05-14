//
//  PenguinBody.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 10/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/PenguinBody.h"
#include "../include/Game.h"

PenguinBody* PenguinBody::player = nullptr;

PenguinBody::PenguinBody(GameObject& associated) : Component(associated){
    
    Sprite* sp = new Sprite(associated, "assets/img/penguin.png");
    associated.AddComponent(sp);
    
    Collider* c = new Collider(associated);
    associated.AddComponent(c);
    
//    pcannon = new penguin cannon?
    
    speed = Vec2(5,5);
    linearSpeed = 0;
    angle = 0;
    hp = 10;
    player = this;
}

PenguinBody::~PenguinBody(){
    player = nullptr;
}

void PenguinBody::Start(){
    
    GameObject* goCannon = new GameObject();
    
    PenguinCannon *pc = new PenguinCannon(*goCannon, associated);
    goCannon->AddComponent(pc);
    
    pcannon = goCannon;
    
    Game::GetInstance().GetState().AddObject(goCannon);
}

void PenguinBody::Update(float dt){
    if(InputManager::GetInstance().IsKeyDown(SDLK_w)){
        if(linearSpeed <= 100){
            linearSpeed += SPEED * dt;
        }
    }
    
    
    if(InputManager::GetInstance().IsKeyDown(SDLK_s)){
        if(linearSpeed >= -100){
            linearSpeed -= SPEED * dt;
        }
    }
    
    if(InputManager::GetInstance().IsKeyDown(SDLK_a)){
        angle -= ANGULARSPEED * dt;
    }
    
    if(InputManager::GetInstance().IsKeyDown(SDLK_d)){
        angle += ANGULARSPEED * dt;
    }
    
    //Setando velocidade
    speed.x = linearSpeed * cos(angle);
    speed.y = linearSpeed * sin(angle);
    
    associated.angleDeg = angle * (180 / PI);
    
    associated.box.x += speed.x;
    associated.box.y += speed.y;
    
}

void PenguinBody::Render(){
    
}

bool PenguinBody::Is(string type){
    if(type == "PenguinBody"){
        return true;
    }
    else{
        return false;
    }
}

void PenguinBody::NotifyCollision(GameObject& other){
    if(other.GetComponent("Bullet")){
        
        if(((Bullet*)other.GetComponent("Bullet"))->targetsPlayer){
            
            hp -= ((Bullet*)other.GetComponent("Bullet"))->GetDamage();
            
            other.RequestDelete();
        
            if(hp <= 0){
                
                GameObject* goExplosao = new GameObject();
                Sprite* sp = new Sprite(*goExplosao, "assets/img/penguindeath.png", 5, 0.1, 0.5);
                goExplosao->AddComponent(sp);
                
                Sound* s = new Sound(*goExplosao, "assets/audio/boom.wav");
                goExplosao->AddComponent(s);
                goExplosao->box = associated.box;
                
                Game::GetInstance().GetState().AddObject(goExplosao);
                
                associated.RequestDelete();
                Camera::Unfollow();
            }
            
        }
    }
}

Vec2 PenguinBody::GetBoxCenterPosition(){
    return  Math::RectCenter(associated.box);
}
