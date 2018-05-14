//
//  Collider.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 11/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Collider.h"

#ifdef DEBUG
#include "Camera.h"
#include "Game.h"

#include <SDL2/SDL.h>
#endif // DEBUG

Collider::Collider(GameObject& associated, Vec2 scale, Vec2 offset) : Component(associated){
    this->scale = scale;
    this->offset = offset;
}

void Collider::Update(float dt){
    box = associated.box;
    box.x += offset.x;
    box.y += offset.y;
    box.w *= scale.x;
    box.h *= scale.y;
}

// Copie o conteúdo dessa função para dentro da sua e adapte o nome das funções para as suas.
// Funções usadas:
// Rect::GetCenter()                - Retorna um Vec2 no centro do Rect
// Vec2::operator-( const Vec2& )    - Subtrai dois Vec2
// Vec2::Rotate( float rad )        - Rotaciona um Vec2 pelo ângulo em radianos passado
void Collider::Render() {
#ifdef DEBUG
    Vec2 center(Math::RectCenter(box));
    SDL_Point points[5];
    
    Vec2 point = Math::Vec2Rotate(associated.angleDeg/(180/PI), (Vec2(box.x, box.y) - center))
    + center - Camera::pos;
    points[0] = {(int)point.x, (int)point.y};
    points[4] = {(int)point.x, (int)point.y};
    
    point = Math::Vec2Rotate(associated.angleDeg/(180/PI), (Vec2(box.x + box.w, box.y) - center))
    + center - Camera::pos;
    points[1] = {(int)point.x, (int)point.y};
    
    point = Math::Vec2Rotate(associated.angleDeg/(180/PI), Vec2(box.x + box.w, box.y + box.h) - center)
    + center - Camera::pos;
    points[2] = {(int)point.x, (int)point.y};
    
    point = Math::Vec2Rotate(associated.angleDeg/(180/PI), Vec2(box.x, box.y + box.h) - center)
    + center - Camera::pos;
    points[3] = {(int)point.x, (int)point.y};
    
    SDL_SetRenderDrawColor(Game::GetInstance().GetRenderer(), 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLines(Game::GetInstance().GetRenderer(), points, 5);
#endif // DEBUG
}

bool Collider::Is(string type){
    if(type == "Collider"){
        return true;
    }
    else{
        return false;
    }
}

void Collider::SetScale(Vec2 scale){
    this->scale = scale;
}

void Collider::SetOffset(Vec2 offset){
    this->offset = offset;
}
