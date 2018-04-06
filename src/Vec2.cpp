//
//  Vec2.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Vec2.h"

Vec2::Vec2(){
    x=y=0;
}

Vec2::Vec2(float x1, float y1){
    x = x1;
    y = y1;
}

Vec2 Vec2::operator+(Vec2 right){
    return Vec2(this->x + right.x, this->y + right.y);
}

Vec2 Vec2::operator-(Vec2 right){
    return Vec2(this->x - right.x, this->y - right.y);
}
