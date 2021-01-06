//
//  BouncingBall.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/26.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "BouncingBall.hpp"

BouncingBall::BouncingBall(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z) {
    // tex for boards
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/bouncingBall.bmp");
    texID_1 = Scene::GetTexture("./bouncingBall.bmp");
}

void BouncingBall::Update(const double &deltaTime) {
    // animation for the bouncing ball
    if (start) {
        current_speed = start_speed;
        bouncing = true;
        start = false;
    }
    
    if (bouncing) {
        current_speed -= gravity;
        if (relative_height + current_speed <= 0) {
            // collide with ground
            relative_height = 0;
            current_speed += resistence;
            if (current_speed >= 0) {
                // stop bouncing
                bouncing = false;
                current_speed = 0;
                relative_height = 0;
            } else {
                current_speed *= -1.0;
            }
        } else {
            relative_height += current_speed;
        }
    }
    
}

void BouncingBall::HandleKey(unsigned char key, int state, int x, int y) {
    switch (key)
    {
        case 't':
            start = true;
            break;
        default:
            break;
    }
}

void BouncingBall::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1] + relative_height, pos[2]);
        DrawBouncingBall();
    glPopMatrix();
}

void BouncingBall::DrawBouncingBall() {
    glPushMatrix();
        GLUquadricObj *quadObj1;
        quadObj1 = gluNewQuadric();
        gluQuadricTexture(quadObj1,GL_TRUE);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texID_1);
        gluSphere(quadObj1,ball_radius,20,20);
    glPopMatrix();
    
    glBindTexture(GL_TEXTURE_2D, NULL);
    // Stop performing texturing
    glDisable(GL_TEXTURE_2D);
}













