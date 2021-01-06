//
//  Dart.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/30.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Dart.hpp"
#include <cmath>

Dart::Dart(GLfloat x, GLfloat y, GLfloat z, GLfloat x_cen, GLfloat y_cen, GLfloat z_cen ) : DisplayableObject(x, y, z), initial_X(x), initial_Y(y), initial_Z(z), x_cen(x_cen), y_cen(y_cen), z_cen(z_cen){
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/dart.obj");
    objl = new ObjLoader("./dart.obj");
}

void Dart::Display() {
    glPushMatrix();
        float X = 0, Y = 0, Z = 0, x = 0, y = 0, z = 0;
        
        if (pickeup) {
            Scene::GetCamera()->GetEyePosition(X, Y, Z);
            Scene::GetCamera()->GetViewDirection(x, y, z);
            position(X, Y, Z);
        }
    
        glTranslatef(pos[0], pos[1], pos[2]);
    
        if (pickeup) {
            float degree =(-x) / sqrt(x*x + z*z);
            float theta = acos(degree) * 180;
            theta /= 3;
            if (z < 0) {
                glRotated(-theta, 0, 1, 0);
            } else if (z > 0) {
                glRotated(theta, 0, 1, 0);
            }
            glRotated(90, 0, 0, 1);
        } else {
            glRotated(90, 1, 0, 0);
        }
        
        glTranslatef(2, 5, 0);
        glScaled(50, 50, 50);
        glColor3f(0.3, 0.7, 0.3);
        DrawDart();
        glColor3f(1, 1, 1);
    glPopMatrix();
}

void Dart::DrawDart() {
    glPushMatrix();
        glRotatef(45, 0, 1, 0);
        objl->Draw();
    glPopMatrix();
}

void Dart::HandleKey(unsigned char key, int state, int x, int y) { 
    switch (key)
    {
        case 'e':
            pickeup = true;
            break;
        case 'r':
            flying = true;
            pickeup = false;
            last_z = pos[2];
            delt_z = (z_cen - last_z) / period;
            break;
        default:
            break;
    }
}


void Dart::Update(const double &deltaTime) {
    // animation for the dart
    if (flying) {
        if (pos[2] >= z_cen) {
            flying = false;
            pos[2] = z_cen;
        } else {
            pos[2] += delt_z;
            delt_z -= 0.3;
        }
    }
}




