//
//  Road.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Road_hpp
#define Road_hpp

#include <stdio.h>
#include "DisplayableObject.h"

#endif /* Road_hpp */

class Road:
    public DisplayableObject
{
public:
    Road(GLfloat x, GLfloat y, GLfloat z);
    ~Road(){};
    
    void Display();
    void DrawRoad();
    
};
