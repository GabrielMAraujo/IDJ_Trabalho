//
//  CameraFollower.h
//  IDJ_Trabalho1
//
//  Created by Gabriel Mota Araújo on 23/04/18.
//  Copyright © 2018 Gabriel Mota Araújo. All rights reserved.
//

#include <iostream>
#include "../include/GameObject.h"
#include "../include/Camera.h"
#include "../include/Component.h"

using namespace std;

class CameraFollower: public Component{
    
public:
    CameraFollower(GameObject& go);
    void Update(float dt);
    void Render();
    bool Is(string type);
    
private:
    
};
