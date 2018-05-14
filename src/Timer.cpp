//
//  Timer.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 11/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Timer.h"

Timer::Timer(GameObject& associated) : Component(associated){
    time = 0;
}

void Timer::Update(float dt){
    time += dt;
}

void Timer::Render(){
    
}

bool Timer::Is(string type){
    if(type == "Timer"){
        return true;
    }
    else{
        return false;
    }
}

void Timer::Restart(){
    time = 0;
}

float Timer::Get(){
    return time;
}
