//
//  Plane.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Plane_hpp
#define Plane_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "ObjLoader.hpp"

#endif /* Plane_hpp */

class Plane :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Plane(GLfloat x, GLfloat y, GLfloat z);
    ~Plane(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);
    void DrawPlane();
    
private:
    ObjLoader *objl;
    GLfloat rotate = 0;
    
    bool start = false;
    bool land = false;
    bool slow_down = false;
    
    float speed = 0;
    float a_speed = 0;
    float a_a_speed = 0.02;
    float max_speed = 1.35;
    
    float y_speed = 3;
    float land_y_speed =8;
    
    
    float z_rotate = 0.5;
    bool rise_once = true;
    bool rising = false;
    
    bool rotating = false;
    
};
