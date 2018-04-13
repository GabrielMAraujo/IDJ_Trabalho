//
//  Face.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 06/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include <string>
#include "../include/GameObject.h"
#include "../include/Sound.h"
#include "../include/Sprite.h"

using namespace std;

class Face: public Component{

public:
    Face(GameObject& associated);
    void Damage(int damage);
    void Update(float dt);
    void Render();
    bool Is(string type);
    
private:
    int hitpoints;

};
