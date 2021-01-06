//
//  Boat.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Boat_hpp
#define Boat_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "ObjLoader.hpp"

#endif /* Boat_hpp */

class Boat :
    public DisplayableObject,
    public Animation
{
public:
    Boat(GLfloat x, GLfloat y, GLfloat z);
    ~Boat(){};
    
    void Display();
    void Update(const double& deltaTime);
    
    void DrawBoat();
    bool checkDistance();
    
private:
    ObjLoader *objl;
    GLint texID_1;
    GLboolean right = true;
    GLfloat speed = +10;
    GLfloat distance = 1000;
    
    GLboolean up = true;
    GLfloat up_speed = 0.6;
    GLfloat up_distance = 36;
};
