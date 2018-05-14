//
//  Timer.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 11/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include "../include/Component.h"

#include <iostream>

class Timer : public Component{
    
public:
    Timer(GameObject& asssociated);
    
    void Update(float dt);
    void Render();
    bool Is(string type);
    
    void Restart();
    float Get();
    
private:
    float time;
    
};
