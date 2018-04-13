//
//  TileSet.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include "../include/Sprite.h"

using namespace std;

class TileSet{
    
public:
    TileSet(int tileWidth, int tileHeight, string file, GameObject &associated);
    void RenderTile(unsigned index, float x, float y);
    int GetTileWidth();
    int GetTileHeight();
private:
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;
    
};
