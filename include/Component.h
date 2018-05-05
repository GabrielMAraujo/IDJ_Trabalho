//
//  Component.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include "../include/GameObject.h"
#include <string>

class GameObject;

using namespace std;

class Component{
public:
    Component(GameObject& associated);
    virtual ~Component();
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual bool Is(string type) = 0;
    virtual void Start();
    
private:

protected:
    GameObject& associated;
    
};
