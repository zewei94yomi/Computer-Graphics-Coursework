//
//  Table.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/16.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"

#endif /* Table_hpp */

class Table:
    public DisplayableObject
{
public:
    Table(GLfloat x, GLfloat y, GLfloat z);
    ~Table(){};
    
    void Display();
    void DrawTable();
    
private:
    ObjLoader *objl;
};
