//
//  Ground.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/11.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Ground_hpp
#define Ground_hpp

#include <stdio.h>
#include "DisplayableObject.h"

#endif /* Ground_hpp */

class Ground :
    public DisplayableObject
{
public:
    Ground(GLfloat x, GLfloat y, GLfloat z);
    ~Ground(){};
    
    void Display();
    
    void DrawGround();
private:
    GLint texID_1;
};
