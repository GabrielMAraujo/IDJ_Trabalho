//
//  main.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <iostream>
#include "../include/Game.h"
#include "../include/TitleState.h"

int main(int argc, const char * argv[]) {
    // insert code here...
//    StageState *s = new StageState();
    TitleState *s = new TitleState();
    Game::GetInstance().Push(s);
    Game::GetInstance().Run();
    
    return 0;
}
