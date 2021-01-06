//
//  Desk.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/19.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Desk_hpp
#define Desk_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#endif /* Desk_hpp */


class Desk :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Desk(GLfloat x, GLfloat y, GLfloat z);
    ~Desk(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}
    
    void DrawDesk();
    void DrawDrawer(float length, float width, float drawer_height, float thickness, float cubeSize);
    
private:
    bool opening = false;
    bool closing = false;
    float drawer_position_z = 0;
    float length = 150;
    float width = 70;
    float height = 100;
    float cubeSize = 10;
    float thickness = 2;
    float drawer_height = 20;
    
    GLint texID_1;
    GLint texID_2;
};
