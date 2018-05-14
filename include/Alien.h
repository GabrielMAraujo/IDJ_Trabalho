//
//  Alien.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 02/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define COOLDOWNSTATE 2

#include "../include/Component.h"
#include "../include/Vec2.h"
#include "../include/Sprite.h"
#include "../include/InputManager.h"
#include "../include/Math.h"
#include "../include/Camera.h"
#include "../include/Minion.h"
#include "../include/State.h"
#include "../include/Collider.h"

#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

class Alien : public Component{
    
public:
    Alien(GameObject& associated, int nMinions);
    ~Alien();
    void Start();
    void Update(float dt);
    void Render();
    bool Is(string type);
    void NotifyCollision(GameObject& other);
    
    static int alienCount;
    
private:
//    class Action{
//    public:
//        enum ActionType{
//            MOVE,
//            SHOOT
//        };
//        Action(ActionType type, float x, float y){
//            this->type = type;
//            pos = Vec2(x, y);
//        }
//        ActionType type;
//        Vec2 pos;
//    };
    
    enum AlienState{
        MOVING,
        RESTING
    };
    AlienState state;
    Timer* restTimer;
    Vec2 destination;
    Vec2 speed;
    int hp;
//    queue<Action> taskQueue;
    vector<GameObject*> minionArray;
};
