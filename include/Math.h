//
//  Math.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <iostream>
#include "Vec2.h"
#include "Rect.h"

class Math{
    
public:
    Vec2 Vec2Add(Vec2 v1, Vec2 v2);
    Vec2 Vec2Sub(Vec2 v1, Vec2 v2);
    Vec2 Vec2MultScalar(Vec2 v1, float f);
    float Vec2Module(Vec2 v1);
    Vec2 Vec2Normalized(Vec2 v1);
    
private:

};
