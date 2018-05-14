//
//  Alien.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 02/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/Alien.h"
#include "../include/Game.h"

int numMinions = 0;
int Alien::alienCount = 0;

Alien::Alien(GameObject& associated, int nMinions) : Component(associated){
    Sprite* sp = new Sprite(associated, "assets/img/alien.png");
    associated.AddComponent(sp);
    Collider* c = new Collider(associated);
    associated.AddComponent(c);
    restTimer = new Timer(associated);
    associated.AddComponent(restTimer);
    
    state = RESTING;
    speed = Vec2(300,300);
    hp = 20;
    numMinions = nMinions;
    alienCount++;
}

Alien::~Alien(){
    for(int i = (int)minionArray.size(); i > 0; i--){
        minionArray.erase(minionArray.begin() + (i-1));
    }
    minionArray.clear();
    alienCount--;
}

void Alien::Start(){
    for(int i = 0; i < numMinions; i++){
        GameObject* goMinion = new GameObject();
        Minion* m = new Minion(*goMinion, associated, i * (360 / 5));
        goMinion->AddComponent(m);
        Game::GetInstance().GetState().AddObject(goMinion);
        minionArray.emplace_back(goMinion);
    }
}

void Alien::Update(float dt){
    
    associated.angleDeg -= 1;
    
//    if(InputManager::GetInstance().MousePress(SDL_BUTTON_LEFT)){
//        //Tiro
//        cout << "atira"<< endl;
//        Action a1 = Action(Action::SHOOT, InputManager::GetInstance().GetMouseX() + Camera::pos.x, InputManager::GetInstance().GetMouseY() + Camera::pos.y);
//        taskQueue.push(a1);
//    }
//
//    if(InputManager::GetInstance().MousePress(SDL_BUTTON_RIGHT)){
//        cout <<"move" << endl;
//        //Movimento
//        Action a2 = Action(Action::MOVE, InputManager::GetInstance().GetMouseX() - (associated.box.w / 2) + Camera::pos.x, InputManager::GetInstance().GetMouseY() - (associated.box.h / 2) + Camera::pos.y);
//        taskQueue.push(a2);
//    }
    
    if(PenguinBody::player != nullptr){
    
        if(state == RESTING){
            if(restTimer->Get() >= COOLDOWNSTATE){
                destination = PenguinBody::player->GetBoxCenterPosition();
                
                state = MOVING;
            }
        }
        
        if(state == MOVING){
            Vec2 atual = Vec2(associated.box.x, associated.box.y);
            
            float dist = Math::Vec2Dist(atual, destination);
            
            float angulo =Math::Vec2LineInclinationX(atual, destination);
            
            //            cout << dist << " : " << distVelocidade << endl;
            if(dist >= 5){
                associated.box.x += speed.x * cos(angulo) * dt;
                associated.box.y += speed.y * sin(angulo) * dt;
            }
            else{
                destination = PenguinBody::player->GetBoxCenterPosition();
                
                int random = rand() % (int)minionArray.size();
                Minion* m = (Minion*)minionArray[random]->GetComponent("Minion");
                
                m->Shoot(destination);
                
                restTimer->Restart();
                state = RESTING;
                
            }
        }
        
    }
    
//    if(taskQueue.size() > 0){
////        cout <<"tq" << taskQueue.front().type << endl;
////        cout << "tq2 " << Action::MOVE << endl;
//        if(taskQueue.front().type == Action::MOVE){
//            Vec2 atual = Vec2(associated.box.x, associated.box.y);
//            Vec2 destino = Vec2(taskQueue.front().pos.x, taskQueue.front().pos.y);
//
//            float dist = Math::Vec2Dist(atual, destino);
//
//            float angulo =Math::Vec2LineInclinationX(atual, destino);
//
//            float distVelocidade = Math::Vec2Dist(speed, Vec2(0,0));
//
////            cout << dist << " : " << distVelocidade << endl;
//            if(dist >= 5){
//                associated.box.x += speed.x * cos(angulo) * dt;
//                associated.box.y += speed.y * sin(angulo) * dt;
//            }
//            else{
//                taskQueue.pop();
//            }
//        }
//        if(taskQueue.front().type == Action::SHOOT){
//
//            int random = rand() % (int)minionArray.size();
//            Minion* m = (Minion*)minionArray[random]->GetComponent("Minion");
//
//            m->Shoot(taskQueue.front().pos);
//
//            taskQueue.pop();
//        }
//
//    }
}

void Alien::Render(){
    
}

bool Alien::Is(string type){
    if(type == "Alien"){
        return true;
    }
    else{
        return false;
    }
}

void Alien::NotifyCollision(GameObject& other){
    if(other.GetComponent("Bullet")){
        if(!((Bullet*)other.GetComponent("Bullet"))->targetsPlayer){
            hp -= ((Bullet*)other.GetComponent("Bullet"))->GetDamage();
            
//            cout << "deleta bala" << endl;
            other.RequestDelete();
            
            if(hp <= 0){
                
                GameObject* goExplosao = new GameObject();
                Sprite* sp = new Sprite(*goExplosao, "assets/img/aliendeath.png", 4, 0.1, 0.4);
                goExplosao->AddComponent(sp);
                goExplosao->box = associated.box;
                
                Sound* s = new Sound(*goExplosao, "assets/audio/boom.wav");
                goExplosao->AddComponent(s);
                
                Game::GetInstance().GetState().AddObject(goExplosao);
                
                associated.RequestDelete();
            }
        }
    }
}
