//
//  Ball.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Ball.hpp"



Ball::Ball(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
    // tex for boards
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/ball.bmp");
    texID_1 = Scene::GetTexture("./ball.bmp");
}


void Ball::Display() {
    glPushMatrix();
        glScaled(0.8, 0.8, 0.8);
        glPushMatrix();
            glTranslatef(pos[0], pos[1], pos[2]);
            DrawFramework(20, 4, 30);
            glTranslatef(0, 50, 0);
            glRotatef(BallRotation, 0, 1, 0);
            glRotatef(-90, 1, 0, 0);
            DrawBall();
        glPopMatrix();
    glPopMatrix();
}


void Ball::DrawBall() {
    glPushMatrix();
        GLUquadricObj *quadObj1;
        quadObj1 = gluNewQuadric();
        // enable texturing
        gluQuadricTexture(quadObj1,GL_TRUE);
        // bind texture
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texID_1);
        // draw the ball
        gluSphere(quadObj1,27,20,20);
    glPopMatrix();
}

void Ball::Update(const double &deltaTime) {
    if (running) {
        if (BallSpeed <= maxRotationSpeed && speedUp) {
            BallSpeed += aRotation;
            if (BallSpeed >= maxRotationSpeed) {
                speedUp = false;
                slowDown = true;
            }
        } else if (BallSpeed >= 0 && slowDown) {
            BallSpeed -= daRotation;
        } else if (BallSpeed <= 0) {
            running = false;
            speedUp = false;
            slowDown = false;
            BallSpeed = 0;
        }
        BallRotation += BallSpeed;
    }
}

void Ball::HandleKey(unsigned char key, int state, int x, int y) {
    switch (key)
    {
        case '7':
            running = true;
            if (BallSpeed <= 0) {
                speedUp = true;
                slowDown = false;
            }
            break;
        default:
            break;
    }
}

void Ball::DrawFramework(float base_a, float base_height, float stand_height) {
    // draw the base
    glPushMatrix();
        glPushMatrix();
            glScalef(base_a, base_height, base_a);
            glutSolidCube(1);
        glPopMatrix();
        
        // draw the stand
        glPushMatrix();
        glRotated(-90, 1, 0, 0);
            GLUquadric *pObj = gluNewQuadric();
            gluCylinder(pObj, 1, 1, stand_height, 100, 100);
        glPopMatrix();
    glPopMatrix();
}



