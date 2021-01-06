//
//  Dart.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/30.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Dart_hpp
#define Dart_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include "ObjLoader.hpp"

#endif /* Dart_hpp */

class Dart :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Dart(GLfloat x, GLfloat y, GLfloat z, GLfloat x_cen, GLfloat y_cen, GLfloat z_cen );
    ~Dart(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}
    
    void DrawDart();
    
private:
    ObjLoader *objl;
    GLboolean pickeup = false;
    GLboolean flying = false;
    GLfloat initial_X;
    GLfloat initial_Y;
    GLfloat initial_Z;
    GLfloat x_cen;
    GLfloat y_cen;
    GLfloat z_cen;
    GLfloat last_x;
    GLfloat last_y;
    GLfloat last_z;
    GLfloat delt_x;
    GLfloat delt_y;
    GLfloat delt_z;
    GLfloat period = 7;
};
