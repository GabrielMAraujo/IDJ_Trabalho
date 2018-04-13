//
//  TileSet.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <stdio.h>
#include "../include/TileSet.h"


TileSet::TileSet(int tileWidth, int tileHeight, string file, GameObject &associated) : tileSet(associated, file){
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    columns = tileSet.GetWidth() / tileWidth;
    rows = tileSet.GetHeight() / tileHeight;
}

void TileSet::RenderTile(unsigned index, float x, float y){
    int numTiles = rows * columns;
    
    if(index != 0xffffffff){
//        cout << "index " << index << endl;
        if(index <= numTiles - 1){
            int linha = index / columns;
//            cout << "linha: " << linha << endl;
            int coluna = index % columns;
//            cout << "coluna: " << coluna << endl;
            
            tileSet.SetClip(coluna*tileWidth, linha*tileHeight, tileWidth, tileHeight);
            tileSet.Render(x, y);
        }
    }
}

int TileSet::GetTileWidth(){
    return tileWidth;
}

int TileSet::GetTileHeight(){
    return tileHeight;
}
