//
//  BouncingBall.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/26.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef BouncingBall_hpp
#define BouncingBall_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include "ObjLoader.hpp"

#endif /* BouncingBall_hpp */

class BouncingBall :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    BouncingBall(GLfloat x, GLfloat y, GLfloat z);
    ~BouncingBall(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}
    
    void DrawBouncingBall();
    
private:
    GLint texID_1;
    GLfloat groud_height;
    GLfloat ball_radius = 15;
    GLfloat relative_height = 0;
    
    GLboolean start = false;
    GLboolean bouncing = false;
    GLfloat start_speed = 20;
    GLfloat current_speed = 0;
    GLfloat gravity = 4;
    GLfloat resistence = 0.6;
};
