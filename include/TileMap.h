//
//  TileMap.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#pragma once

#include "../include/GameObject.h"
#include "../include/TileSet.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class TileMap : public Component{
    
public:
    TileMap(GameObject& associated, string file, TileSet* tileSet);
    void Load(string file);
    void SetTileSet(TileSet* tileSet);
    int& At(int x, int y, int z = 0);
    void Render();
    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
    int GetWidth();
    int GetHeight();
    int GetDepth();
    void Update(float dt);
    bool Is(string type);
    

private:
    vector<int> tileMatrix;
    TileSet* tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;
    
};
