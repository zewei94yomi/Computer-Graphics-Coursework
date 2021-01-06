//
//  DartBoard.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/30.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef DartBoard_hpp
#define DartBoard_hpp

#include <stdio.h>
#include "DisplayableObject.h"

#endif /* DartBoard_hpp */

class DartBoard :
    public DisplayableObject
{
public:
    DartBoard(GLfloat x, GLfloat y, GLfloat z);
    ~DartBoard(){};
    
    void Display();
    
    void DrawBoard();
    
private:
    
};
