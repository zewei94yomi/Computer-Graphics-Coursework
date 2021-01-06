//
//  Bin.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Bin_hpp
#define Bin_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"

#endif /* Bin_hpp */

class Bin:
    public DisplayableObject
{
public:
    Bin(GLfloat x, GLfloat y, GLfloat z);
    ~Bin(){};
    
    void Display();
    void DrawBin();
private:
    
    ObjLoader *objl;
};
