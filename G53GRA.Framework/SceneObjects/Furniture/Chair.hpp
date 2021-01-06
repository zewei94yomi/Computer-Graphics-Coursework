//
//  Chair.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/23.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Chair_hpp
#define Chair_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"

#endif /* Chair_hpp */

class Chair:
    public DisplayableObject
{
public:
    Chair(GLfloat x, GLfloat y, GLfloat z);
    ~Chair(){};
    
    void Display();
    void DrawChair();
private:
    
    ObjLoader *objl;
};
