//
//  Light.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Light_hpp
#define Light_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"

#endif /* Light_hpp */

class Light:
    public DisplayableObject
{
public:
    Light(GLfloat x, GLfloat y, GLfloat z);
    ~Light(){};
    
    void Display();
    void DrawLight();
    
private:
    
    ObjLoader *objl;
};
