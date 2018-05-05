//
//  Bullet.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 05/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Bullet.h"


Bullet::Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, string sprite) : Component(associated){
    Sprite* sp = new Sprite(associated, sprite);
    associated.AddComponent(sp);
    
    this->speed = Vec2(speed * cos(angle), speed * sin(angle));
    
    this->damage = damage;
    distanceLeft = maxDistance;
    
    associated.angleDeg = Math::Vec2InclinationX(this->speed) * (180/PI);
}

void Bullet::Update(float dt){
    
    Vec2 speedDt = Vec2(speed.x * dt, speed.y * dt);
    
    associated.box.x += speedDt.x;
    associated.box.y += speedDt.y;
    
    distanceLeft -= Math::Vec2Module(speedDt);
    
    if(distanceLeft <= 0){
        associated.RequestDelete();
    }
    
}

void Bullet::Render(){
    
}

bool Bullet::Is(string type){
    if(type == "Bullet"){
        return true;
    }
    else{
        return false;
    }
}

int Bullet::GetDamage(){
    return damage;
}
