//
//  Clock.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/22.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Clock_hpp
#define Clock_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"      

#endif /* Clock_hpp */


class Clock :
    public DisplayableObject,
    public Animation
{
public:
    Clock(GLfloat x, GLfloat y, GLfloat z);
    ~Clock(){};
    
    void Display();
    void Update(const double& deltaTime);
    
    float Mysecond(struct tm *ptr);
    float Mymin(struct tm *ptr);
    float Myhour(struct tm *ptr);
    
    void DrawClock();
    
};
    
