//
//  TitleState.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/TitleState.h"

GameObject* titulo;
GameObject* texto;
Timer* timerBlink;
Text* t;

TitleState::TitleState(){
    titulo = new GameObject();
    Sprite* sp = new Sprite(*titulo, "assets/img/title.jpg");
    titulo->AddComponent(sp);
    timerBlink = new Timer(*titulo);
    titulo->AddComponent(timerBlink);
    objectArray.emplace_back(titulo);
    
    texto = new GameObject();
    texto->box.x = 270;
    texto->box.y = 490;
    SDL_Color cinza = {100, 100, 100, 255};
    t = new Text(*texto, "assets/font/Call me maybe.ttf", 48, Text::TextStyle::SOLID, "Press Space to continue", cinza);
    texto->AddComponent(t);
    objectArray.emplace_back(texto);
    
    GameData::playerVictory = false;
}

TitleState::~TitleState(){
    
}

void TitleState::LoadAssets(){
    
}

void TitleState::Update(float dt){
    
    Camera::pos.x = 0;
    Camera::pos.y = 0;
    
    if(InputManager::GetInstance().QuitRequested() || InputManager::GetInstance().KeyPress(SDLK_ESCAPE)){
        quitRequested = true;
    }
    
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){
        StageState *ss = new StageState();
        Game::GetInstance().Push(ss);
    }
    
    titulo->Update(dt);
    texto->Update(dt);
    timerBlink->Update(dt);
    if(timerBlink->Get() >= COOLDOWNBLINK){
        timerBlink->Restart();
        
        if(t->GetText() == ""){
            t->SetText("Press Space to continue");
        }
        else if(t->GetText() == "Press Space to continue"){
            t->SetText("");
        }
    }
}

void TitleState::Render(){
    titulo->Render();
    texto->Render();
}

void TitleState::Start(){
    
}

void TitleState::Pause(){
    
}

void TitleState::Resume(){
    
}
