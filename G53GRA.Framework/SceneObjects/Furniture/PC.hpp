//
//  PC.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef PC_hpp
#define PC_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"
#endif /* PC_hpp */

class PC:
    public DisplayableObject
{
public:
    PC(GLfloat x, GLfloat y, GLfloat z);
    ~PC(){};
    
    void Display();
    void DrawPC();
    
private:
    
    ObjLoader *objl;
    GLint texID_1;
};
