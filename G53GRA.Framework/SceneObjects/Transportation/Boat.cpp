//
//  Boat.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Boat.hpp"


Boat::Boat(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z) { 
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/boat.obj");
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/boat.bmp");
    objl = new ObjLoader("./boat.obj");
    texID_1 = Scene::GetTexture("./boat.bmp");
}


void Boat::Display() { 
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glScaled(50, 50, 50);
        DrawBoat();
    glPopMatrix();
}


void Boat::Update(const double &deltaTime) {
    // animation for the moving right step
    if (right) {
        if (pos[0] <= distance) {
            pos[0] += speed;
        } else {
            right = false;
        }
    } else {
        if (pos[0] >= -1000) {
            pos[0] -= speed;
        } else {
            right = true;
        }
    }
    
    // animation for the moving left step
    if (up) {
        if (pos[1] <= up_distance) {
            pos[1] += up_speed;
        } else {
            up = false;
        }
    } else {
        if (pos[1] >= 26) {
            pos[1] -= up_speed;
        } else {
            up = true;
        }
    }
}


void Boat::DrawBoat() {
    // bind texture for the boat object
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texID_1);

    objl->Draw();
    
    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);
}


