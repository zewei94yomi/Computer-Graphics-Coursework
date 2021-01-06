//
//  Fan.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Fan.hpp"


Fan::Fan(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
    rotation[1] = 0;
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/fan.obj");
    objl = new ObjLoader("./fan.obj");
}


void Fan::Display() { 
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(rotation[1], 0, 1, 0);
        glScaled(40, 40, 40);
        glColor3f(0.25, 0.25, 0.25);
        DrawFan();
        glColor3f(1, 1, 1);
    glPopMatrix();
}


void Fan::DrawFan() { 
    objl->Draw();
}

/// update the Z rotation variable with change in time
void Fan::Update(const double& deltaTime)
{
    // rotation for the van
    if (isOn) {
        if (currentSpeed < maxSpeed) {
            currentSpeed += acceleratedSpeed;
        }
        
    } else {
        if (currentSpeed > 0) {
            currentSpeed -= acceleratedSpeed;
        }
    }
    rotation[1] += currentSpeed;
}

/// set scale variables based on a key press
void Fan::HandleKey(unsigned char key, int state, int x, int y)
{
    switch (key)
    {
        case 'f':
            isOn = true;
            break;
        case 'g':
            isOn = false;
            break;
        default:
            break;
    }
}
