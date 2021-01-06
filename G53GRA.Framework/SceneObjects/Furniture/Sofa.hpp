//
//  Sofa.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/16.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Sofa_hpp
#define Sofa_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"

#endif /* Sofa_hpp */

class Sofa:
    public DisplayableObject
{
public:
    Sofa(GLfloat x, GLfloat y, GLfloat z);
    ~Sofa(){};
    
    void Display();
    void DrawSofa();
    
private:
    ObjLoader *objl;
};
