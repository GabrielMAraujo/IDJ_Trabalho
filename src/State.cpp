//
//  State.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 15/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "State.h"
#include "Game.h"

State::State(){
    cout << "State::State()" << endl;
    quitRequested = false;
    bg = Sprite();
    music = Music();
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::LoadAssets(){
    bg.Open("./img/ocean.jpg");
    music.Open("./audio/stageState.ogg");
}

void State::Update(float dt){
    if(SDL_QuitRequested()){
        quitRequested = true;
    }
}

void State::Render(){
    bg.Render(0, 0);
}
