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

Alien::Alien(GameObject& associated, int nMinions) : Component(associated){
    Sprite* sp = new Sprite(associated, "assets/img/alien.png");
    associated.AddComponent(sp);
    
    speed = Vec2(300,300);
    hp = 20;
}

Alien::~Alien(){
    for(int i = (int)minionArray.size(); i > 0; i--){
        minionArray.erase(minionArray.begin() + (i-1));
    }
    minionArray.clear();
}

void Alien::Start(){
    for(int i = 0; i < 5; i++){
        GameObject* goMinion = new GameObject();
        Minion* m = new Minion(*goMinion, associated, i * (360 / 5));
        goMinion->AddComponent(m);
        Game::GetInstance().GetState().AddObject(goMinion);
        minionArray.emplace_back(goMinion);
    }
}

void Alien::Update(float dt){
    
    associated.angleDeg -= 1;
    
    if(InputManager::GetInstance().MousePress(SDL_BUTTON_LEFT)){
        //Tiro
        cout << "atira"<< endl;
        Action a1 = Action(Action::SHOOT, InputManager::GetInstance().GetMouseX() + Camera::pos.x, InputManager::GetInstance().GetMouseY() + Camera::pos.y);
        taskQueue.push(a1);
    }
    
    if(InputManager::GetInstance().MousePress(SDL_BUTTON_RIGHT)){
        cout <<"move" << endl;
        //Movimento
        Action a2 = Action(Action::MOVE, InputManager::GetInstance().GetMouseX() - (associated.box.w / 2) + Camera::pos.x, InputManager::GetInstance().GetMouseY() - (associated.box.h / 2) + Camera::pos.y);
        taskQueue.push(a2);
    }
    
    if(taskQueue.size() > 0){
//        cout <<"tq" << taskQueue.front().type << endl;
//        cout << "tq2 " << Action::MOVE << endl;
        if(taskQueue.front().type == Action::MOVE){
            Vec2 atual = Vec2(associated.box.x, associated.box.y);
            Vec2 destino = Vec2(taskQueue.front().pos.x, taskQueue.front().pos.y);
            
            float dist = Math::Vec2Dist(atual, destino);
            
            float angulo =Math::Vec2LineInclinationX(atual, destino);
            
            float distVelocidade = Math::Vec2Dist(speed, Vec2(0,0));
            
//            cout << dist << " : " << distVelocidade << endl;
            if(dist >= 5){
                associated.box.x += speed.x * cos(angulo) * dt;
                associated.box.y += speed.y * sin(angulo) * dt;
            }
            else{
                taskQueue.pop();
            }
        }
        if(taskQueue.front().type == Action::SHOOT){
            
            int random = rand() % (int)minionArray.size();
            Minion* m = (Minion*)minionArray[random]->GetComponent("Minion");
            
            m->Shoot(taskQueue.front().pos);
            
            taskQueue.pop();
        }
        
        if(hp <= 0){
            associated.RequestDelete();
        }
        
    }
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
