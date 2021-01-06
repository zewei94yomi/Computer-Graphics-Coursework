//
//  Building.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/14.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Building.hpp"

Building::Building(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/building.obj");
    objl = new ObjLoader("./building.obj");
}

void Building::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glScalef(20, 20, 20);
        glColor3f(255.0/255,140.0/255,0.0/255);
        DrawBuilding();
        glColor3f(1,1,1);
    glPopMatrix();
}

void Building::DrawBuilding() {
    objl->Draw();
}

void Building::HandleKey(unsigned char key, int state, int x, int y) { 
    switch (key)
    {
        case 'c':
            rising = true;
            if (checkDistance()) {
                camera_on = true;
                Scene::GetCamera()->setCamera(pos[0], pos[1]+60, pos[2]);
            }
            break;
        case 'v':
            camera_on = false;
            Scene::GetCamera()->setCamera(-400, 150, 300);
        default:
            break;
    }
}


void Building::Update(const double &deltaTime) {
    // animation for the rising step
    if (rising && pos[1] <= 1000) {
        pos[1] += 5;
        if (camera_on) {
            Scene::GetCamera()->changeCamera(0, 5, 0);
        }
        if (pos[1] >= 1000) {
            rising = false;
            still = true;
            still_down = true;
        }
    }
    
    // animation for the still step
    if (still) {
        if (still_down && pos[1] >= 1000 - flow) {
            pos[1] -= 1.8;
            if (camera_on) {
                Scene::GetCamera()->changeCamera(0, -1.8, 0);
            }
            if (pos[1] <= 1000 - flow) {
                still_down = false;
                still_up = true;
            }
        }
        if (still_up && pos[1] <= 1000 + flow) {
            pos[1] += 1.8;
            if (camera_on) {
                Scene::GetCamera()->changeCamera(0, +1.8, 0);
            }
            if (pos[1] >= 1000 + flow) {
                still_up = false;
                still_down = true;
            }
        }
    }
}

// check if the camera and the object is close enough
bool Building::checkDistance() {
    float x, y, z;
    Scene::GetCamera()->GetEyePosition(x, y, z);
    float distance = sqrt((pos[0]-x)*(pos[0]-x) + (pos[2]-z) * (pos[2]-z));
    if (distance <= 300) {
        return true;
    } else {
        return false;
    }
}


