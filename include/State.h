//
//  State.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include "../include/GameObject.h"

using namespace std;

class State{
    
public:
    State();
    virtual ~State();
    virtual void LoadAssets() = 0;
    virtual void Update(float dt) = 0;
    virtual void Render() = 0;
    virtual void Start() = 0;
    virtual void Pause() = 0;
    virtual void Resume() = 0;
    virtual GameObject* AddObject(GameObject* object);
    virtual GameObject* GetObjectPtr(GameObject* object);
    bool PopRequested();
    bool QuitRequested();
    
    
private:
    
protected:
    void StartArray();
    virtual void UpdateArray(float dt);
    virtual void RenderArray();
    
    bool popRequested;
    bool quitRequested;
    bool started;
    vector<unique_ptr<GameObject>> objectArray;
    
    
    
};
