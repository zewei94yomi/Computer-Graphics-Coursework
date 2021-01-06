//
//  Room.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/18.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"
#include "ObjLoader.hpp"

#endif /* Room_hpp */

class Room :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Room(GLfloat x, GLfloat y, GLfloat z);
    ~Room(){};
    
    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}
    
    void DrawWalls();
    void DrawWindow(float window_length, float window_height, float window_width);
    void DrawDoor(float door_length, float door_height,  float door_width);
    
private:
    GLint texID_1;
    GLint texID_2;
    GLint texID_3;
    GLint texID_4;
    GLint texID_5;
    GLint texID_6;
    
    ObjLoader *objl1;
    
    GLboolean door_opening = false;
    GLboolean door_closing = false;
    
    GLboolean window_opening = false;
    GLboolean window_closing = false;
    
    GLfloat lock_rotation = 0;
    GLfloat door_rotation = 0;
    GLfloat window_trans = 0;
    
};
