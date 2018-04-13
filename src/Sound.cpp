//
//  Sound.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 04/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/Sound.h"
#include "../include/Resources.h"

Sound::Sound(GameObject& associated) : Component(associated){
    chunk = nullptr;
}

Sound::Sound(GameObject& associated, string file) : Sound(associated){
    Open(file);
}

Sound::~Sound(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
//        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, times - 1);
}

void Sound::Stop(){
    if(chunk != nullptr){
        Mix_HaltChannel(channel);
    }
}

bool Sound::IsPlaying(){
    return Mix_Playing(channel);
}

void Sound::Open(string file){
//    chunk = Mix_LoadWAV(file.c_str());
    chunk = Resources::GetSound(file);
    if(chunk == nullptr){
        printf("Erro no Mix_LoadWAV: %s\n", Mix_GetError());
    }
}

bool Sound::IsOpen(){
    return (chunk != nullptr);
}

void Sound::Update(float dt){
    
}

void Sound::Render(){
    
}

bool Sound::Is(string type){
    if(type == "Sound"){
        return true;
    }
    else{
        return false;
    }
}
