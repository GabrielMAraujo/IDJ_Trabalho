//
//  Sprite.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 16/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Sprite.h"
#include "../include/Game.h"

Sprite::Sprite(GameObject& associated) : Component(associated){
    
    texture = nullptr;
}

Sprite::Sprite(GameObject& associated, string file) : Component(associated){
    cout << "Sprite::Sprite()" << endl;
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }
}

void Sprite::Open(string file){
    if(texture != nullptr){
        SDL_DestroyTexture(texture);
    }

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    
    if(texture == nullptr){
        cout << "Erro no carregamento de textura do tipo " << SDL_GetError() << endl;
    }
    
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
    associated.box.w = width;
    associated.box.h = height;
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y= y;
    clipRect.w = w;
    clipRect.h = h;
    
    associated.box.w = w;
    associated.box.h = h;
}

void Sprite::Render(){
    SDL_Rect dstrect;
    dstrect.x = associated.box.x;
    dstrect.y = associated.box.y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return (texture != nullptr);
}

void Sprite:: Update(float dt){
    
}

bool Sprite:: Is(string type){
    if(type == "Sprite"){
        return true;
    }
    else{
        return false;
    }
}
