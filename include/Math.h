//
//  Math.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include <iostream>
#include "../include/Vec2.h"
#include "../include/Rect.h"
#include <math.h>

class Math{
    
public:
    static Vec2 Vec2Add(Vec2 v1, Vec2 v2);
    static Vec2 Vec2Sub(Vec2 v1, Vec2 v2);
    static Vec2 Vec2MultScalar(Vec2 v1, float f);
    static float Vec2Module(Vec2 v1);
    static Vec2 Vec2Normalized(Vec2 v1);
    static float Vec2Dist(Vec2 v1, Vec2 v2);
    static float Vec2InclinationX(Vec2 v1);
    static float Vec2LineInclinationX(Vec2 v1, Vec2 v2);
    static Vec2 Vec2Rotate(float angle, Vec2 v1);
    static  Rect RectAddVec2(Rect r1, Vec2 v1);
    static Vec2 RectCenter(Rect r1);
    static float RectCentersDistance(Rect r1, Rect r2);
    static bool RectContains(Rect r1, Vec2 v1);
    
private:

};
