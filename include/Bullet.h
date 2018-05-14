//
//  Bullet.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 05/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define PI 3.14

#include <iostream>
#include "../include/GameObject.h"
#include "../include/Vec2.h"
#include "../include/Sprite.h"
#include "../include/Math.h"
#include "../include/Collider.h"

class Bullet : public Component{
public:
    
    Bullet(GameObject& associated, float angle, float speed, int damage, float maxDistance, string sprite, int frameCount, float frameTime, bool targetsPlayer);
    void Update(float dt);
    void Render();
    bool Is(string type);
    int GetDamage();
    void NotifyCollision(GameObject& other);
    bool targetsPlayer;
    
private:
    Vec2 speed;
    float distanceLeft;
    int damage;
    
};
