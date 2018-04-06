//
//  Face.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 06/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/Face.h"

Face::Face(GameObject& associated) : Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    cout << "Dano: " << hitpoints;
    if(hitpoints <= 0){
        associated.RequestDelete();
        ((Sound*)associated.GetComponent("Sound"))->Play();
    }
}

void Face::Update(float dt){
    
}

void Face::Render(){
    
}

bool Face::Is(string type){
    if(type == "Face"){
        return true;
    }
    else{
        return false;
    }
}
