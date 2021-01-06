//
//  Bed.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/18.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Bed_hpp
#define Bed_hpp

#include <stdio.h>
#include "DisplayableObject.h"

#endif /* Bed_hpp */

class Bed :
    public DisplayableObject
{
public:
    Bed(GLfloat x, GLfloat y, GLfloat z);
    ~Bed(){};
    
    void Display();
    void DrawBed();

private:
    GLint texID_1;
    GLint texID_2;
};
