//
//  Minion.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//


#include "../include/Minion.h"
#include "../include/Game.h"

Minion::Minion(GameObject& associated, GameObject& alienCenter, float arcOffsetDeg)  : Component(associated), alienCenter(alienCenter){

    Sprite* sp = new Sprite(associated, "assets/img/minion.png");
    
    float random = (float)(rand() % 6 + 10) / 10;
    sp->SetScaleX(random, random);
    
    associated.AddComponent(sp);
    
    Collider* c = new Collider(associated);
    associated.AddComponent(c);
    
    
    
    arc = arcOffsetDeg * PI / 180;
    
    //Se quiser botar os minions circulares, fazer (RANGEX * cos(arc)
    //Função rosa implementada
    associated.box.x = (this->alienCenter.box.x + this->alienCenter.box.w/2) + (RANGEX * cos(7*arc) * cos(arc)) - associated.box.w/2;
    associated.box.y = (this->alienCenter.box.y + this->alienCenter.box.h/2) + (RANGEY * cos(7*arc) * sin(arc)) - associated.box.h/2;
}

void Minion::Update(float dt){
    
    associated.angleDeg = arc * (180 / PI);
    
    arc += VELANGULAR * dt;
    
    associated.box.x = (this->alienCenter.box.x + this->alienCenter.box.w/2) + (RANGEX * cos(7*arc) * cos(arc)) - associated.box.w/2;
    associated.box.y = (this->alienCenter.box.y + this->alienCenter.box.h/2) + (RANGEY * cos(7*arc) * sin(arc)) - associated.box.h/2;
}

void Minion::Render(){
    
}

bool Minion::Is(string type){
    if(type == "Minion"){
        return true;
    }
    else{
        return false;
    }
}

void Minion::Shoot(Vec2 target){

    float angulo = Math::Vec2LineInclinationX(Math::RectCenter(associated.box), target);
    
    GameObject* goBullet = new GameObject();
    goBullet->box.x = associated.box.x + (associated.box.w / 2);
    goBullet->box.y = associated.box.y + (associated.box.h / 2);
    Bullet* b = new Bullet(*goBullet, angulo , 500, 10, 500, "assets/img/minionbullet2.png", 3, 0.2, true);
    goBullet->AddComponent(b);
    Game::GetInstance().GetCurrentState().AddObject(goBullet);
}

void Minion::Start(){
    
}
