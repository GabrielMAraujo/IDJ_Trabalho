//
//  State.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 15/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include "../include/State.h"
#include "../include/Game.h"

State::State(){
    cout << "State::State()" << endl;
    quitRequested = false;
    music = Music();
}

State::~State(){
 
    objectArray.clear();
    
}

bool State::QuitRequested(){
    return quitRequested;
}

void State::LoadAssets(){
//    bg.Open("assets/img/ocean.jpg");
    
    GameObject* bg = new GameObject();
    Sprite* sp = new Sprite(*bg, "assets/img/ocean.jpg");
    bg->AddComponent(sp);
    objectArray.emplace_back(bg);
    
    //Declaração para player futuro
    GameObject* player = new GameObject();
    CameraFollower *cf = new CameraFollower(*player);
    player->AddComponent(cf);
    
    music.Open("assets/audio/stageState.ogg");
    
    GameObject* goTileMap = new GameObject();
    goTileMap->box.x = goTileMap->box.y = 0;
    TileSet* tileSet = new TileSet(64, 64, "assets/img/tileset.png", *goTileMap);
    TileMap* tileMap = new TileMap(*goTileMap, "assets/map/tileMap.txt", tileSet);
    
    goTileMap->AddComponent(tileMap);
    objectArray.emplace_back(goTileMap);
}

void State::Update(float dt){

//    Input();
    if(InputManager::GetInstance().QuitRequested() || InputManager::GetInstance().KeyPress(SDLK_ESCAPE)){
//        cout << "Pediu pra sair" << endl;
        quitRequested = true;
    }
    
    if(InputManager::GetInstance().KeyPress(SDLK_SPACE)){
        //Criar face
        int mouseX = InputManager::GetInstance().GetMouseX();
        int mouseY = InputManager::GetInstance().GetMouseY();
        Vec2 objPos;
        objPos = Math::Vec2Rotate((-PI + PI*(rand() % 1001)/500.0 ), Vec2( 200, 0 )) + Vec2( mouseX, mouseY);
        AddObject((int)objPos.x + Camera::pos.x, (int)objPos.y + Camera::pos.y);
    }
    
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }
    
    for(int i = (int)objectArray.size() - 1; i >= 0; i--){
//        cout << i << endl;
        if(objectArray[i]->IsDead()){
//            cout << "Sprite: " << objectArray[i]->GetComponent("Sprite") << endl;;
            Sound *s = (Sound*) objectArray[i]->GetComponent("Sound");
            if(s){
                if(!(s->IsPlaying())){
                    objectArray.erase(objectArray.begin() + i);
                }
                else{
                    objectArray.erase(objectArray.begin() + i);
                }
            }
            
        }
    }
    
    Camera::Update(dt);
    
}

void State::Render(){
    
    for(int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
    
}

//void State::Input() {
//    SDL_Event event;
//    int mouseX, mouseY;
//
//    // Obtenha as coordenadas do mouse
//    SDL_GetMouseState(&mouseX, &mouseY);
//
//    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
//    while (SDL_PollEvent(&event)) {
//
//        // Se o evento for quit, setar a flag para terminação
//        if(event.type == SDL_QUIT) {
//            quitRequested = true;
//        }
//
//        // Se o evento for clique...
//        if(event.type == SDL_MOUSEBUTTONDOWN) {
//
//            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
//            for(int i = (int)objectArray.size() - 1; i >= 0; --i) {
//                // Obtem o ponteiro e casta pra Face.
//                GameObject* go = (GameObject*) objectArray[i].get();
//                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
//                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
//                // ao usar get(), violamos esse princípio e estamos menos seguros.
//                // Esse código, assim como a classe Face, é provisório. Futuramente, para
//                // chamar funções de GameObjects, use objectArray[i]->função() direto.
//
////                if(go->box.Contains( {(float)mouseX, (float)mouseY} ) ) {
//                if(Math::RectContains(go->box, Vec2((float)mouseX, (float)mouseY))){
//                    Face* face = (Face*)go->GetComponent( "Face" );
//                    if ( nullptr != face ) {
//                        // Aplica dano
//                        cout << "Oi" << endl;
//                        face->Damage(std::rand() % 10 + 10);
//                        // Sai do loop (só queremos acertar um)
//                        break;
//                    }
//                }
//            }
//        }
//        if( event.type == SDL_KEYDOWN ) {
//            // Se a tecla for ESC, setar a flag de quit
//            if( event.key.keysym.sym == SDLK_ESCAPE ) {
//                quitRequested = true;
//            }
//            // Se não, crie um objeto
//            else {
////                Vec2 objPos = Vec2( 200, 0 ).GetRotated( -PI + PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
//                Vec2 objPos;
//                objPos = Math::Vec2Rotate((-PI + PI*(rand() % 1001)/500.0 ), Vec2( 200, 0 )) + Vec2( mouseX, mouseY);
//                AddObject((int)objPos.x, (int)objPos.y);
//            }
//        }
//    }
//}

void State::AddObject(int mouseX, int mouseY){
    
    cout << "Add object" << endl;
    
    GameObject* go = new GameObject();
    Sprite* sp = new Sprite(*go, "assets/img/penguinface.png");
    go->box.x = mouseX - go->box.w/2;
    go->box.y = mouseY - go->box.h/2;
    go->AddComponent(sp);
    
    Sound* s = new Sound(*go, "assets/audio/boom.wav");
    go->AddComponent(s);
    
    Face* f = new Face(*go);
    go->AddComponent(f);
    objectArray.emplace_back(go);
}


