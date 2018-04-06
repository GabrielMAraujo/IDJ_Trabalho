//
//  Vec2.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

class Vec2{
    
public:
    float x, y;
    Vec2();
    Vec2(float x1, float y1);
    Vec2 operator+(Vec2 right);
    Vec2 operator-(Vec2 right);
    
private:
    
};
