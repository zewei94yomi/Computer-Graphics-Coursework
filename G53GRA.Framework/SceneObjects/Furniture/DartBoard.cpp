//
//  DartBoard.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/30.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "DartBoard.hpp"

const GLfloat Pi = 3.1415926536;
const GLfloat R=50.0f;
const int n=200;
static GLfloat angle=2*Pi;

DartBoard::DartBoard(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z){
}

void DartBoard::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glScalef(0.5, 0.5, 0.5);
        DrawBoard();
    glPopMatrix();
}

void DartBoard::DrawBoard() {
    glPushMatrix();
        glRotated(180, 0, 1, 0);
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*1.2*cos(2*Pi/n*i), R*1.2*sin(2*Pi/n*i), 99);
            }
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i), 99.1);
            }
        glEnd();
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*0.8*cos(2*Pi/n*i), R*0.8*sin(2*Pi/n*i), 99.2);
            }
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*0.6*cos(2*Pi/n*i), R*0.6*sin(2*Pi/n*i), 99.3);
            }
        glEnd();
        glColor3f(1,0,0);
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*0.4*cos(2*Pi/n*i), R*0.4*sin(2*Pi/n*i), 99.4);
            }
        glEnd();
        glColor3f(1,1,1);
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*0.2*cos(2*Pi/n*i), R*0.2*sin(2*Pi/n*i), 99.5);
            }
        glEnd();
    glPopMatrix();
}






