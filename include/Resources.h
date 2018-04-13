//
//  Resources.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 13/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL

#include "../include/SDL_include.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Resources{
  
public:
    static SDL_Texture* GetImage(string file);
    static void ClearImages();
    
    static Mix_Music* GetMusic(string file);
    static void ClearMusics();
    
    static Mix_Chunk* GetSound(string file);
    static void ClearSounds();
    
private:
    static unordered_map<string, SDL_Texture*> imageTable;
    static unordered_map<string, Mix_Music*> musicTable;
    static unordered_map<string, Mix_Chunk*> soundTable;
    
};
