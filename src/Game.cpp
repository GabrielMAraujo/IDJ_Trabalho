//
//  Game.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//


#include "../include/Game.h"
#include "../include/Resources.h"

Game* Game::instance = NULL;

Game::Game(string title, int width, int height){
    cout << "Game::Game()" << endl;
    if(instance == nullptr){
        instance = this;
    }
    
    //Init do SDL
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0){
        cout << "Erro ao abrir SDL do tipo " << SDL_GetError() << endl;
    }
    
    //Init de vídeo
    if(IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0){
        cout << "Erro ao iniciar formatos de imagem" << endl;
    }
    
    //Init de áudio
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID);
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
        cout << "Erro ao abrir áudio" << endl;
    }
    Mix_AllocateChannels(32);
    
    //Criando janela
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr){
        cout << "Erro ao criar janela" << endl;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr){
         cout << "Erro ao criar renderizador" << endl;
    }
    
    state = new State();
}

Game::~Game(){
    
    state = nullptr;
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
    
void Game::Run(){
    GetState().LoadAssets();
    while(!state->QuitRequested()){
        state->Update(0.033);// 1/30 = 0.033
//        SDL_RenderClear(renderer);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
    Resources::ClearImages();
    Resources::ClearMusics();
    Resources::ClearSounds();
}
    
SDL_Renderer* Game::GetRenderer(){
    return renderer;
}
    
State& Game::GetState(){
   return *state;
}

Game& Game::GetInstance(){
    if(instance == nullptr){
        instance = new Game("Gabriel Mota Araújo - 13/0009130", 1024, 600);
    }
    
    return *instance;
}

