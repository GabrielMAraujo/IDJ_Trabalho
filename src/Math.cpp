//
//  Math.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Math.h"

Vec2 Math::Vec2Add(Vec2 v1, Vec2 v2){
    Vec2 v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    return v3;
}

Vec2 Math::Vec2Sub(Vec2 v1, Vec2 v2){
    Vec2 v3;
    v3.x = v1.x - v2.x;
    v3.y = v1.y - v2.y;
    return v3;
}

Vec2 Math::Vec2MultScalar(Vec2 v1, float f){
    Vec2 v3;
    v3.x = v1.x * f;
    v3.y = v1.y * f;
    return v3;
}

float Math::Vec2Module(Vec2 v1){
    return sqrt(pow(v1.x, 2) + pow(v1.y, 2));
}

Vec2 Math::Vec2Normalized(Vec2 v1){
    Vec2 v3;
    float module = Vec2Module(v1);
    v3.x = v1.x / module;
    v3.y = v1.y / module;
    return v3;
}

float Math::Vec2Dist(Vec2 v1, Vec2 v2){
    Vec2 v3;
    v3.x = v2.x - v1.x;
    v3.y = v2.y - v2.y;
    return Vec2Module(v3);
}

float Math::Vec2InclinationX(Vec2 v1){
//    return atan2(v1.y, v1.x) * 180 / 3.14;
    return atan2(v1.y, v1.x);
}

float Math::Vec2LineInclinationX(Vec2 v1, Vec2 v2){
    float incX = v2.x - v1.x;
    float incY = v2.y - v1.y;
    
//    return atan2(incY, incX) * 180 / 3.14;
    return atan2(incY, incX);
}

Vec2 Math::Vec2Rotate(float angle, Vec2 v1){
    Vec2 rotated;
//    float rad = angle * 3.14 / 180.0;
    float rad = angle;
    rotated.x = v1.x * cos(rad) - v1.y * sin(rad);
    rotated.y = v1.y * cos(rad) + v1.x * sin(rad);
    
    return rotated;
}

Rect Math::RectAddVec2(Rect r1, Vec2 v1){
    Rect r3;
    r3.x = r1.x + v1.x;
    r3.y = r1.y + v1.y;
    return r3;
}

Vec2 Math::RectCenter(Rect r1){
    Vec2 v1;
    v1.x = r1.x + (r1.w / 2);
    v1.y = r1.y + (r1.h / 2);
    return v1;
}

float Math::RectCentersDistance(Rect r1, Rect r2){
    Vec2 c1 = RectCenter(r1);
    Vec2 c2 = RectCenter(r2);
    return Vec2Dist(c1, c2);
}

bool Math::RectContains(Rect r1, Vec2 v1){
    bool containsX = false, containsY = false;
    if( (v1.x >= r1.x) && (v1.x <= (r1.x + r1.w)) ){
        containsX = true;
    }
    
    if( (v1.y >= r1.y) && (v1.y <= (r1.y + r1.h)) ){
        containsY = true;
    }
    
    return containsX & containsY;
}
