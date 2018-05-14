//
//  PenguinCannon.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 10/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define COOLDOWN 0.5

#include "../include/GameObject.h"
#include "../include/Sprite.h"
#include "../include/InputManager.h"
#include "../include/Math.h"
#include "../include/Bullet.h"
#include "../include/Collider.h"
#include "../include/Timer.h"

#include <iostream>

class PenguinCannon : public Component{
    
public:
    PenguinCannon(GameObject& associated, GameObject& penguinBody);
    void Start();
    void Update(float dt);
    void Render();
    bool Is(string type);
    void Shoot();
    
private:
    GameObject* pbody;
    float angle;
};
