//
//  EndState.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include "../include/Music.h"
#include "../include/State.h"
#include "../include/GameData.h"
#include "../include/Sprite.h"
#include "../include/InputManager.h"
#include "../include/Game.h"
#include "../include/TitleState.h"

class EndState : public State{
    
public:
    EndState();
    ~EndState();
    void LoadAssets();
    void Update(float dt);
    void Render();
    void Start();
    void Pause();
    void Resume();
    
private:
    Music backgroundMusic;
};
