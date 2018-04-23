//
//  TileMap.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//


#include "../include/TileMap.h"
#include "../include/Camera.h"

TileMap::TileMap(GameObject& associated, string file, TileSet* tileSet) : Component(associated){
    Load(file);
    this->tileSet = tileSet;
}

void TileMap::Load(string file){
    fstream arquivoTileMap;
    char virgula;
    int parametro;
    
    arquivoTileMap.open(file);
    
    if(arquivoTileMap.fail()){
        cout << "Erro ao abrir arquivo de tilemap." << endl;
    }
    
    else{
        //Receber primeiros parâmetros(altura, largura e profundidade)
        arquivoTileMap >> mapWidth >> virgula >> mapHeight >> virgula >> mapDepth >> virgula;
        
        //Receber o resto dos parâmetros e salvar no tileMatrix
        while(!arquivoTileMap.eof()){
            arquivoTileMap >> parametro >> virgula;
            tileMatrix.emplace_back(parametro - 1);
        }
    }
    
    
    
}

void TileMap::SetTileSet(TileSet* tileSet){
    this->tileSet = tileSet;
}

int& TileMap::At(int x, int y, int z){
    int index = x + y * mapWidth + z * (mapWidth * mapHeight);
    return tileMatrix[index];
}

void TileMap::Render(){
//    cout << "camera: " <<Camera::pos.x << " " << Camera::pos.y << endl;
//    Vec2 parallaxSpeed = Camera::speed * 2;
    for(int i = 0; i < mapDepth; i++){
        RenderLayer(i, Camera::pos.x*(i+1) , Camera::pos.y*(i+1));
    }
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY){
    for(int y = 0; y < mapHeight; y++){
        for(int x = 0; x < mapWidth; x++){
            tileSet->RenderTile(At(x,y,layer),  -cameraX + x*tileSet->GetTileWidth(), -cameraY + y*tileSet->GetTileHeight());
        }
    }
}

int TileMap::GetWidth(){
    return mapWidth;
}

int TileMap::GetHeight(){
    return mapHeight;
}

int TileMap::GetDepth(){
    return mapDepth;
}

void TileMap::Update(float dt){
    
}

bool TileMap::Is(string type){
    if(type == "TileMap"){
        return true;
    }
    else{
        return false;
    }
}
