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

Sprite::Sprite( GameObject& associated, string file, int frameCount, float frameTime, float secondsToSelfDestruct) : Component(associated){
    cout << "Sprite::Sprite()" << endl;
    texture = nullptr;
    Open(file);
    scale = Vec2(1,1);
    this->frameCount = frameCount;
    this->frameTime = frameTime;
    this->secondsToSelfDestruct = secondsToSelfDestruct;
    if(secondsToSelfDestruct > 0){
        selfDestructCount = new Timer(associated);
        associated.AddComponent(selfDestructCount);
    }
    
    SetFrame(currentFrame);
}

Sprite::~Sprite(){
//    if(texture != nullptr){
//        SDL_DestroyTexture(texture);
//    }
}

void Sprite::Open(string file){
//    if(texture != nullptr){
//        SDL_DestroyTexture(texture);
//    }

//    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    texture = Resources::GetImage(file);
    
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
    if(associated.GetComponent("Face") == nullptr){
        SDL_Rect dstrect;
        dstrect.x = associated.box.x - Camera::pos.x;
        dstrect.y = associated.box.y - Camera::pos.y;
        dstrect.w = clipRect.w * scale.x;
        dstrect.h = clipRect.h * scale.y;
        SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, associated.angleDeg, nullptr, SDL_FLIP_NONE);
    }
}

void Sprite::Render(int x, int y){
    SDL_Rect dstrect;
    dstrect.x = x;
    dstrect.y = y;
    dstrect.w = clipRect.w;
    dstrect.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect);
}

int Sprite::GetWidth(){
    return (width / frameCount) * scale.x;
}

int Sprite::GetHeight(){
    return height * scale.y;
}

bool Sprite::IsOpen(){
    return (texture != nullptr);
}

void Sprite:: Update(float dt){
    timeElapsed += dt;
    if(timeElapsed >= frameTime){
        timeElapsed = 0;
        currentFrame++;
        
        if((currentFrame >= frameCount) && (secondsToSelfDestruct == 0)){
            currentFrame = 0;
        }
        SetFrame(currentFrame);
    }
    
    
    
    if(secondsToSelfDestruct > 0){
        
        if (selfDestructCount->Get() >= secondsToSelfDestruct) {
            associated.RequestDelete();
        }
        
    }
}

bool Sprite:: Is(string type){
    if(type == "Sprite"){
        return true;
    }
    else{
        return false;
    }
}

void Sprite::SetScaleX(float scaleX, float scaleY){
    float sx, sy;
    if(scaleX != 0){
        sx = scaleX;
    }
    else{
        sx = scale.x;
    }
    if(scaleY != 0){
        sy = scaleY;
    }
    else{
        sy = scale.y;
    }
    
    scale = Vec2(sx, sy);
}

Vec2 Sprite::GetScale(){
    return scale;
}


void Sprite::SetFrame(int frame){
    currentFrame = frame;
    SetClip((width / (frameCount)) * currentFrame, 0, (width / frameCount), height);
}

void Sprite::SetFrameCount(int frameCount){
    this->frameCount = frameCount;
    currentFrame = 0;
    
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0, 0, width, height);
    associated.box.w = width;
    associated.box.h = height;
    
    SetFrame(currentFrame);
}


void Sprite::SetFrameTime(int frameTime){
    this->frameTime = frameTime;
}
