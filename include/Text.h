//
//  Text.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 18/05/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL
#define INCLUDE_SDL_TTF

#include "../include/SDL_include.h"
#include "../include/Component.h"
#include "../include/Camera.h"
#include "../include/Game.h"

class Text : public Component{
    
public:
    enum TextStyle{
        SOLID,
        SHADED,
        BLENDED
    };
    Text(GameObject& associated, string fontFile, int fontSize, TextStyle style, string text, SDL_Color color);
    ~Text();
    void Update(float dt);
    void Render();
    bool Is(string type);
    void SetText(string text);
    void SetColor(SDL_Color color);
    void SetStyle(TextStyle style);
    void SetFontFile(string fontFile);
    void SetFontSize(int fontSize);
    string GetText();
    
private:
    void RemakeTexture();
    
    TTF_Font* font;
    SDL_Texture* texture;
    string text;
    TextStyle style;
    string fontFile;
    int fontSize;
    SDL_Color color;
    
};
