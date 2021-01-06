//
//  Pillow.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Pillow_hpp
#define Pillow_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"

#endif /* Pillow_hpp */

class Pillow:
    public DisplayableObject
{
public:
    Pillow(GLfloat x, GLfloat y, GLfloat z);
    ~Pillow(){};
    
    void Display();
    void DrawPillow();
private:
    
    ObjLoader *objl;
};
