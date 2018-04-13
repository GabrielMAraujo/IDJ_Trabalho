//
//  Resources.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 13/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Resources.h"
#include "../include/Game.h"

unordered_map<string, SDL_Texture*> Resources::imageTable;
unordered_map<string, Mix_Music*> Resources::musicTable;
unordered_map<string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(string file){
    if(imageTable.find(file) == imageTable.end()){
        imageTable[file] = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
        cout << "criou textura" << endl;
    }
    else{
        cout << "textura já existe" << endl;
    }
    return imageTable[file];
}

void Resources::ClearImages(){
    for(auto i = imageTable.begin(); i != imageTable.end(); i++){
        SDL_DestroyTexture(i->second);
    }
    imageTable.clear();
}

Mix_Music* Resources::GetMusic(string file){
     if(musicTable.find(file) == musicTable.end()){
         musicTable[file] = Mix_LoadMUS(file.c_str());
     }
     return musicTable[file];
}

void Resources::ClearMusics(){
    for(auto i = musicTable.begin(); i != musicTable.end(); i++){
        Mix_FreeMusic(i->second);
    }
    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(string file){
    if(soundTable.find(file) == soundTable.end()){
        soundTable[file] = Mix_LoadWAV(file.c_str());
    }
    return soundTable[file];
}

void Resources::ClearSounds(){
    for(auto i = soundTable.begin(); i != soundTable.end(); i++){
            Mix_FreeChunk(i->second);
    }
    soundTable.clear();
}
