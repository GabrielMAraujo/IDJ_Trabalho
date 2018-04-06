//
//  main.cpp
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 12/03/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <iostream>
#include "../include/Game.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Game::GetInstance().Run();
    
    return 0;
}
