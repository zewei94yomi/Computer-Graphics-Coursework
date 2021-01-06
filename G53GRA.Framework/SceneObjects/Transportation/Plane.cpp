//
//  Plane.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Plane.hpp"

Plane::Plane(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/plane.obj");
    objl = new ObjLoader("./plane.obj");
}

void Plane::Display()
{
    glPushMatrix();
        glRotated(rotate, 0, 1, 0);
        glPushMatrix();
            glTranslatef(pos[0], pos[1], pos[2]);
            glRotatef(rotation[0], 1, 0, 0);
            glRotatef(rotation[1], 0, 1, 0);
            glRotatef(rotation[2], 0, 0, 1);
            glPushMatrix();
                glRotatef(90, 0, 1, 0);
                glScalef(30, 30, 30);
                DrawPlane();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

void Plane::DrawPlane() {
    objl->Draw();
}

void Plane::Update(const double &deltaTime) {
    // animation for the start step
    if (start) {
        pos[0] += speed;
        if (a_speed < max_speed) {
            speed += a_speed;       // acceleration speed
            a_speed += a_a_speed;   // acceleration of acceleration speed
        } else {
            // reach the maximum speed, and is ready to rise
            rising = true;
        }
        
        if (rising) {
            // going up
            pos[1] += y_speed;
        }
        
        if (rise_once && rising) {
            // uplift the head of the plane and rise the plane body
            rotation[2] += z_rotate;
            if (rotation[2] >= 20) {
                // rotate to the maximum angle and stop to rotate
                rise_once = false;
            }
        }
    }
    
    // animation for the landing step
    if (land) {
        pos[0] += speed;            // has an initial speed
        if (slow_down) {
            speed -= a_speed;       // acceleration speed
            a_speed += a_a_speed;   // acceleration of acceleration speed
        }
        if (pos[1] - land_y_speed >= 10) {
            pos[1] -= land_y_speed;
        } else {
            // land on the ground
            slow_down = true;
        }
        if (speed <= 0) {
            // finish the whole process of the landing
            land = false;
        }
    }
}

void Plane::HandleKey(unsigned char key, int state, int x, int y) { 
    switch (key) {
        case 'z':
            start = true;
            land = false;
            position(-1500, 10, 1000);
            speed = 0;
            a_speed = 0;
            rotation[0] = 0;
            rotation[1] = 0;
            rotation[2] = 0;
            rising = false;
            rise_once = true;
            break;
        case 'x':
            start = false;
            land = true;
            slow_down = false;
            position(-2500, 500, 1000);
            speed = 35;
            a_speed = 0;
            rotation[0] = 0;
            rotation[1] = 0;
            rotation[2] = 0;
            rising = false;
            rise_once = true;
            break;
        default:
            break;
    }
}

