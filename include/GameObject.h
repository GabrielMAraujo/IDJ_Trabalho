//
//  GameObject.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../include/Component.h"
#include "../include/Rect.h"
//#include "../include/Sound.h"

using namespace std;

class Component;

//class Sound;

class GameObject{
public:
    GameObject();
    ~GameObject();
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component *cpt);
    void RemoveComponent(Component *cpt);
    Component* GetComponent(string type);
    Rect box;
    
private:
    vector<Component*> components;
    bool isDead;
    
};
