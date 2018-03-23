//
//  Music.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "Music.h"

Music::Music(){
    music = nullptr;
}
Music::Music(string file){
    cout << "Music::Music()" << endl;
    music = nullptr;
    Open(file);
}

void Music::Play(int times = -1){
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop = 1500){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(string file){
    music = Mix_LoadMUS(file.c_str());
    if(music == nullptr){
        cout << "Erro ao carregar música do tipo " << SDL_GetError() << endl;
    }
    //Gamb boa abaixo
    else{
        Play();
    }
}

bool Music::IsOpen(){
    return (music != nullptr);
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}
