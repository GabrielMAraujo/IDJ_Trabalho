//
//  Text.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/Text.h"

Text::Text(GameObject& associated, string fontFile, int fontSize, TextStyle style, string text, SDL_Color color) : Component(associated){
    
    this->fontFile = fontFile;
    this->fontSize = fontSize;
    this->style = style;
    this->text = text;
    this->color = color;
    texture = nullptr;
    
    RemakeTexture();
}
Text::~Text(){
    if(texture){
        SDL_DestroyTexture(texture);
    }
}

void Text::Update(float dt){
    
}

void Text::Render(){
    if(texture){
        
        SDL_Rect clipRect;
        clipRect.x = 0;
        clipRect.y = 0;
        clipRect.w = associated.box.w;
        clipRect.h = associated.box.h;
        
        
        SDL_Rect dstrect;
        dstrect.x = associated.box.x - Camera::pos.x;
        dstrect.y = associated.box.y - Camera::pos.y;
        dstrect.w = clipRect.w;
        dstrect.h = clipRect.h;
        
        SDL_RenderCopyEx(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstrect, associated.angleDeg, nullptr, SDL_FLIP_NONE);
    }
}

bool Text::Is(string type){
    if(type == "Text"){
        return true;
    }
    else{
        return false;
    }
}

void Text::SetText(string text){
    this->text = text;
    RemakeTexture();
}

void Text::SetColor(SDL_Color color){
    cout << "set color";
    this->color = color;
    RemakeTexture();
}

void Text::SetStyle(TextStyle style){
    this->style = style;
    RemakeTexture();
}

void Text::SetFontFile(string fontFile){
    this->fontFile = fontFile;
    RemakeTexture();
}

void Text::SetFontSize(int fontSize){
    this->fontSize = fontSize;
    RemakeTexture();
}

string Text::GetText(){
    return text;
}

void Text::RemakeTexture(){
    
    if(texture){
        SDL_DestroyTexture(texture);
    }
    
    font = Resources::GetFont(fontFile, fontSize);
    
    SDL_Surface *s = nullptr;
    if(style == SOLID){
        s = TTF_RenderText_Solid(font, text.c_str(), color);
    }
    else if(style == SHADED){
        SDL_Color preto = {0,0,0,255};
        s = TTF_RenderText_Shaded(font, text.c_str(), color, preto);
    }
    else if(style == BLENDED){
        s = TTF_RenderText_Blended(font, text.c_str(), color);
    }
    
    texture = SDL_CreateTextureFromSurface(Game::GetInstance().GetRenderer(), s);
    SDL_FreeSurface(s);
    
    if(texture){
        associated.box.w = s->w;
        associated.box.h = s->h;
    }
    
}
