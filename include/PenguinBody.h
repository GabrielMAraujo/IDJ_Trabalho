//
//  PenguinBody.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 10/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define SPEED 5
#define PI 3.14
#define ANGULARSPEED PI/4

#include "../include/Component.h"
#include "../include/Vec2.h"
#include "../include/Sprite.h"
#include "../include/PenguinCannon.h"
#include "../include/InputManager.h"
#include "../include/Collider.h"

#include <iostream>

class PenguinBody : public Component{
    
public:
    PenguinBody(GameObject& associated);
    ~PenguinBody();
    
    void Start();
    void Update(float dt);
    void Render();
    bool Is(string type);
    void NotifyCollision(GameObject& other);
    Vec2 GetBoxCenterPosition();
    
    static PenguinBody* player;
    
private:
    GameObject* pcannon;
    Vec2 speed;
    float linearSpeed;
    float angle;
    int hp;
    
};
