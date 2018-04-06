//
//  GameObject.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/GameObject.h"

using namespace std;


GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    for(int i = (int)components.size(); i > 0; i--){
        components.erase(components.begin() + (i - 1));
    }
    components.clear();
}

void GameObject::Update(float dt){
    for(int i = 0; i < components.size(); i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    for(int i = 0; i < components.size(); i++){
        components[i]->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component *cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component *cpt){
    for(int i = 0; i < components.size(); i++){
        if(components[i] == cpt){
            components.erase(components.begin() + i);
        }
    }
}

Component* GameObject::GetComponent(string type){
    for(int i = 0; i < components.size(); i++){
        if(components[i]->Is(type)){
            return components[i];
        }
    }
    return nullptr;
}
