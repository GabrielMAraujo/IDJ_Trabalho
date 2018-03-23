//
//  Rect.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "Rect.h"


Rect::Rect(){
    x=y=w=h=0;
}

Rect::Rect(float x1, float y1, float w1, float h1){
    x = x1;
    y = y1;
    w = w1;
    h = h1;
}
