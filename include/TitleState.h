//
//  TitleState.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define COOLDOWNBLINK 0.75

#include <iostream>

#include "../include/GameObject.h"
#include "../include/Sprite.h"
#include "../include/InputManager.h"
#include "../include/State.h"
#include "../include/StageState.h"
#include "../include/Game.h"
#include "../include/Text.h"

using namespace std;

class TitleState : public State{
    
public:
    TitleState();
    ~TitleState();
    void LoadAssets();
    void Update(float dt);
    void Render();
    void Start();
    void Pause();
    void Resume();
    
private:
    
};
