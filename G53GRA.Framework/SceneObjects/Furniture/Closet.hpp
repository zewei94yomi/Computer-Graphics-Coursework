//
//  Closet.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/18.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Closet_hpp
#define Closet_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#endif /* Closet_hpp */

class Closet :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Closet(GLfloat x, GLfloat y, GLfloat z);
    ~Closet(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}

    void DrawCloset();
    
private:
    float xrot = 0.0;
    float yrot = 0.0;
    float zrot = 0.0;
    bool opening = false;
    bool closing = false;
    
    GLint texID_1;
    GLint texID_2;
};
