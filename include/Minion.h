//
//  Minion.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define PI 3.14
#define VELANGULAR PI/2
#define RANGEX 100
#define RANGEY 100

#include "../include/GameObject.h"
#include "../include/Vec2.h"
#include "../include/Sprite.h"
#include "../include/Bullet.h"
#include "../include/Math.h"
#include "../include/Collider.h"

#include <iostream>

using namespace std;

class Minion : public Component{
public:
    Minion(GameObject& associated, GameObject& alienCenter, float arcOffsetDeg = 0);
    void Update(float dt);
    void Render();
    bool Is(string type);
    void Shoot(Vec2 target);
    void Start();
    
private:
    GameObject& alienCenter;
    float arc;
};
