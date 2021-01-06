//
//  Skybox.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/14.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Skybox_hpp
#define Skybox_hpp

#include <stdio.h>
#include "DisplayableObject.h"

#endif /* Skybox_hpp */

class Skybox :
    public DisplayableObject {
public:
    Skybox(Camera * c);
    ~Skybox();
    
    void Display();
    void draw();

private:
    Camera * camera;
        
    typedef unsigned int uint;
    typedef const char * pcStr;
    uint textures[6];
    static uint _loadTexture(pcStr filename);
};
