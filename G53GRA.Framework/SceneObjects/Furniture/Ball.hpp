//
//  Ball.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Ball_hpp
#define Ball_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include "ObjLoader.hpp"

#endif /* Ball_hpp */

class Ball :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Ball(GLfloat x, GLfloat y, GLfloat z);
    ~Ball(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}
    
    void DrawBall();
    void DrawFramework(float base_a, float base_height, float stand_height);
    
private:
    GLint texID_1;
    
    GLboolean running = false;
    GLboolean speedUp = false;
    GLboolean slowDown = false;
    GLfloat maxRotationSpeed = 80;
    GLfloat BallRotation = 0;   // current rotation
    GLfloat BallSpeed = 0;      // v
    
    GLfloat aRotation = 30;     // +a
    GLfloat daRotation = 3;     // -a
};
