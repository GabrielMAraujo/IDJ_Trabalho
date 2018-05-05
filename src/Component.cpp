//
//  Component.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/Component.h"

Component::Component(GameObject& associated):associated(associated){}
Component::~Component(){}
void Component::Start(){}
