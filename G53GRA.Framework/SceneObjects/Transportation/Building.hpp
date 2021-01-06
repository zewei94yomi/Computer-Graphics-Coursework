//
//  Building.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/14.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Building_hpp
#define Building_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "ObjLoader.hpp"
#include "Animation.h"
#include "Input.h"


#endif /* Building_hpp */

class Building :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Building(GLfloat x, GLfloat y, GLfloat z);
    ~Building(){};
    
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}
    
    void Display();
    void DrawBuilding();
    bool checkDistance();

private:
    
    ObjLoader *objl;
    GLfloat flow = 50;
    GLboolean rising = false;
    GLboolean still = true;
    GLboolean still_up = false;
    GLboolean still_down = false;
    GLboolean camera_on = false;

};
