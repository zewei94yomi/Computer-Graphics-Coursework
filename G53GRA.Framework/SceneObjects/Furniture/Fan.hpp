//
//  Fan.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Fan_hpp
#define Fan_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"
#include "Animation.h"
#include "Input.h"

#endif /* Fan_hpp */


class Fan:
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Fan(GLfloat x, GLfloat y, GLfloat z);
    ~Fan(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}
    
    void DrawFan();
private:
    
    ObjLoader *objl;
    
    GLfloat maxSpeed = 35;
    GLfloat acceleratedSpeed = 0.5;
    GLfloat currentSpeed = 0;
    
    GLboolean isOpening = false;
    GLboolean isClosing = false;
    GLboolean isOn = false;
};
