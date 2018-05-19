//
//  State.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "State.h"

State::State(){
    popRequested = false;
    quitRequested = false;
    started = false;
}

State::~State(){
    objectArray.clear();
}

void State::LoadAssets(){
    
}

void State::Update(float dt){
    
}

void State::Render(){
    
}

void State::Start(){
    
}

void State::Pause(){
    
}

void State::Resume(){
    
}

GameObject* State::AddObject(GameObject* object){
    objectArray.emplace_back(object);
    if(started){
        object->Start();
    }
    return objectArray[objectArray.size()].get();
}

GameObject* State::GetObjectPtr(GameObject* object){
    for(int i = 0; i < objectArray.size(); i++){
        if(objectArray[i].get() == object){
            return objectArray[i].get();
        }
    }
    return nullptr;
}

bool State::PopRequested(){
    return popRequested;
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::StartArray(){
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Start();
    }
}

void State::UpdateArray(float dt){
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }
}

void State::RenderArray(){
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
}
