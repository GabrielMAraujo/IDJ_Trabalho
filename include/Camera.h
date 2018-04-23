//
//  Camera.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 20/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include <iostream>
#include "../include/GameObject.h"
#include "../include/Vec2.h"
#include "../include/InputManager.h"

class Camera{
    
public:
    static void Follow(GameObject* newFocus);
    static void Unfollow();
    static void Update(float dt);
    
    static Vec2 pos;
    static Vec2 speed;
    
private:
    static GameObject* focus;
    
};
