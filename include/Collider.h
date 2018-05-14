//
//  Collider.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 11/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include "../include/GameObject.h"
#include "../include/Vec2.h"

#include <iostream>

class Collider : public Component{
    
public:
    Collider(GameObject& associated, Vec2 scale = {1,1}, Vec2 offset = {0,0});
    
    void Update(float dt);
    void Render();
    bool Is(string type);
    void SetScale(Vec2 scale);
    void SetOffset(Vec2 offset);
    
    Rect box;
    
private:
    Vec2 scale;
    Vec2 offset;
    
};
