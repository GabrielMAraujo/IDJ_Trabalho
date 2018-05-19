//
//  EndState.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/EndState.h"

GameObject* bg;
GameObject* textoFim;

EndState::EndState(){
    
    
    bg = new GameObject();
    Sprite* sp;
    backgroundMusic = Music();
    
    if(GameData::playerVictory){
        sp = new Sprite(*bg, "assets/img/win.jpg");
        backgroundMusic.Open("assets/audio/endStateWin.ogg");
    }
    
    else{
        sp = new Sprite(*bg, "assets/img/lose.jpg");
        backgroundMusic.Open("assets/audio/endStateLose.ogg");
    }
    
    bg->AddComponent(sp);
    
    backgroundMusic.Play(1);
    
    textoFim = new GameObject();
    textoFim->box.x = 80;
    textoFim->box.y = 300;
    SDL_Color preto = {0, 0, 0, 255};
    Text* t = new Text(*textoFim, "assets/font/Call me maybe.ttf", 36, Text::TextStyle::SOLID, "Press Space to go back to the menu or press ESC to quit", preto);
    textoFim->AddComponent(t);
}

EndState::~EndState(){
    
}

void EndState::LoadAssets(){
    
}

void EndState::Update(float dt){
    
    Camera::pos.x = 0;
    Camera::pos.y = 0;
    
    if(InputManager::GetInstance().QuitRequested() || InputManager::GetInstance().KeyPress(SDLK_ESCAPE)){
        quitRequested = true;
    }
    
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){
        popRequested = true;
        TitleState *ts = new TitleState();
        Game::GetInstance().Push(ts);
    }
    
    bg->Update(dt);
    textoFim->Update(dt);
}

void EndState::Render(){
    bg->Render();
    textoFim->Render();
}

void EndState::Start(){
    
}

void EndState::Pause(){
    
}

void EndState::Resume(){
    
}
