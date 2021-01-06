//
//  Desk.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/19.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Desk.hpp"
#include <iostream>
//#define STB_IMAGE_IMPLEMENTATION    // include之前必须定义
//#include "stb_image.h"

Desk::Desk(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
    // tex for boards
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/desk.bmp");
    texID_1 = Scene::GetTexture("./desk.bmp");
}

void Desk::Display()
{
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        DrawDesk();
    glPopMatrix();
}



void Desk::Update(const double& deltaTime){
    // animation for the drawers
    if (opening && !closing) {
        if (drawer_position_z <= width - 2*thickness) {
            drawer_position_z += 40.0f * static_cast<float>(deltaTime);     // opening the drawer
        } else {
            opening = false;
        }
    } else if (closing) {
        if (drawer_position_z >= 0) {
            drawer_position_z -= 40.0f * static_cast<float>(deltaTime);     // closing the drawer
            opening = false;
        } else {
            closing = false;
        }
    }
}

void Desk::HandleKey(unsigned char key, int state, int x, int y){
    switch (key)
    {
        case '5':
            opening = true;
            break;
        case '6':
            closing = true;
            break;
        default:
            break;
    }
}

void Desk::DrawDesk() { 
    // Enable Texturing
    glEnable(GL_TEXTURE_2D);

    // Enable setting the colour of the material the cube is made from
    // as well as the material for blending.
    glEnable(GL_COLOR_MATERIAL);

    // Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, texID_1);
    
    
     //start to draw the desk
    glPushMatrix();
        // draw set the texture for the desk
        glBegin(GL_QUADS);
            // draw the top(out) desk board
            glNormal3f(0, 1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2 -thickness/2, thickness/2+0.1, -width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2 -thickness/2, thickness/2+0.1, width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(length/2 +thickness/2, thickness/2+0.1, width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(length/2 +thickness/2, thickness/2+0.1, -width/2);
    
            // draw the top(in) desk board
            glNormal3f(0, -1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2 -thickness/2, -thickness/2-0.1, -width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(length/2 +thickness/2, -thickness/2-0.1, -width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(length/2 +thickness/2, -thickness/2-0.1, width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2 -thickness/2, -thickness/2-0.1, width/2);
    
            // draw the down(in) desk board
            glNormal3f(0, 1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2, thickness/2-drawer_height+0.1, -width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2, thickness/2-drawer_height+0.1, width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(length/2, thickness/2-drawer_height+0.1, width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(length/2, thickness/2-drawer_height+0.1, -width/2);
    
            // draw the down(out) desk board
            glNormal3f(0, -1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2, -thickness/2-drawer_height-0.1, -width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(length/2, -thickness/2-drawer_height-0.1, -width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(length/2, -thickness/2-drawer_height-0.1, width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2, -thickness/2-drawer_height-0.1, width/2);
    
            // draw the back(out) desk board
            glNormal3f(0, 0, -1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2, 0, -width/2 - 0.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(length/2, 0, -width/2 - 0.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(length/2, -drawer_height, -width/2 - 0.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2, -drawer_height, -width/2 - 0.1);
    
            // draw the back(in) desk board
            glNormal3f(0, 0, 1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2, 0, -width/2 + thickness + 0.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2, -drawer_height, -width/2 + thickness+ 0.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(length/2, -drawer_height, -width/2 + thickness+ 0.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(length/2, 0, -width/2 + thickness+ 0.1);
    
            // draw the right(out) desk board
            glNormal3f(1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(+length/2 + thickness/2 + 0.1, 0, +width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(+length/2 + thickness/2 + 0.1, -height, +width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(+length/2 + thickness/2 + 0.1, -height, -width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(+length/2 + thickness/2 + 0.1, 0, -width/2);
    
            // draw the right(in) desk board
            glNormal3f(-1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(+length/2 - thickness/2 - 0.1, 0, +width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(+length/2 - thickness/2 - 0.1, 0, -width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(+length/2 - thickness/2 - 0.1, -height, -width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(+length/2 - thickness/2 - 0.1, -height, +width/2);
    
            // draw the left(out) desk board
            glNormal3f(-1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2 - thickness/2 - 0.1, 0, +width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-length/2 - thickness/2 - 0.1, 0, -width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-length/2 - thickness/2 - 0.1, -height, -width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2 - thickness/2 - 0.1, -height, +width/2);
    
            // draw the left(in) desk board
            glNormal3f(1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-length/2 + thickness/2 + 0.1, 0, +width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-length/2 + thickness/2 + 0.1, -height, +width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-length/2 + thickness/2 + 0.1, -height, -width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-length/2 + thickness/2 + 0.1, 0, -width/2);
        glEnd();
        glColor3f(1, 1, 1);
    
        // draw the top board
        glPushMatrix();
            glScalef((length+thickness/2 + 1)/cubeSize, thickness/cubeSize, width/cubeSize);
            glColor3f(1, 1, 1);
            glutSolidCube(cubeSize);
        glPopMatrix();

        // draw second board
        glTranslatef(0, -drawer_height, 0); // go to the second board origin
        glPushMatrix();
            glScalef(length/cubeSize, thickness/cubeSize, width/cubeSize);
            glColor3f(1, 1, 1);
            glutSolidCube(cubeSize);
        glPopMatrix();

        // draw the back board
        glPushMatrix();
            glTranslatef(0, +drawer_height/2, -width/2 + thickness / 2);
            glScalef(length/cubeSize, drawer_height/cubeSize, thickness/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();

        // draw the middle board
        glPushMatrix();
            glTranslatef(0, drawer_height/2, 0);
            glScalef(thickness/cubeSize, drawer_height/cubeSize, width/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();

        // draw the two drawer
        glPushMatrix();
            glTranslatef(-length/4, thickness/2, drawer_position_z);
            DrawDrawer(length, width, drawer_height, thickness, cubeSize);
            glTranslatef(+length/2, 0, 0);
            DrawDrawer(length, width, drawer_height, thickness, cubeSize);
        glPopMatrix();

        // start to draw the left and right boards
        glPushMatrix();
            glTranslatef(-length/2, -(height/2-drawer_height), 0);  // go to the left board origin
            glPushMatrix();
                glScalef(thickness/cubeSize, height/cubeSize, width/cubeSize);
                glutSolidCube(cubeSize);
            glPopMatrix();
            glTranslatef(length, 0, 0); // go to the right board origin
            glPushMatrix();
                glScalef(thickness/cubeSize, height/cubeSize, width/cubeSize);
                glutSolidCube(cubeSize);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    
    // Stop blending textures and colours
    glDisable(GL_COLOR_MATERIAL);

    // Bind to the blank buffer to stop ourselves accidentaly
    // using the wrong texture in the next draw call
    glBindTexture(GL_TEXTURE_2D, NULL);
    
    // Stop performing texturing
    glDisable(GL_TEXTURE_2D);
}


void Desk::DrawDrawer(float length, float width, float drawer_height, float thickness, float cubeSize) {
    // set the size of the drawer
    float drawer_length = length / 2 - thickness * 2;
    float drawer_width = width - thickness;
    float drawer_real_height = drawer_height - thickness;
    float drawer_thickness = thickness;
    
    GLint tempID = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/1.bmp");
    
    // Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, tempID);
    
    glPushMatrix();
    glColor3f(222.0/255,184.0/255,135.0/255);
    
        // draw the down board
        glPushMatrix();
            glScalef(drawer_length/cubeSize, drawer_thickness/cubeSize, drawer_width/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
        // draw the texture for it
        glBegin(GL_QUADS);
            // draw the down(in) desk board
            glNormal3f(0, 1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-drawer_length/2, drawer_thickness/2 + 0.1, -drawer_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-drawer_length/2, drawer_thickness/2 + 0.1, +drawer_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(+drawer_length/2, drawer_thickness/2 + 0.1, +drawer_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(+drawer_length/2, drawer_thickness/2 + 0.1, -drawer_width/2);
        glEnd();

        // draw the left board
        glTranslatef(-drawer_length/2, drawer_real_height/2, 0);
        glPushMatrix();
            glScalef(drawer_thickness/cubeSize, drawer_real_height/cubeSize, drawer_width/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
        // draw the texture for it
        glBegin(GL_QUADS);
            // draw the left(in) desk board
            glNormal3f(1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(thickness/2+0.1, drawer_height/2 - thickness/2, +drawer_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(thickness/2+0.1, -drawer_height/2, +drawer_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(thickness/2+0.1, -drawer_height/2, -drawer_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(thickness/2+0.1, drawer_height/2 - thickness/2, -drawer_width/2);
        glEnd();

        // draw the right board
        glTranslatef(drawer_length, 0, 0);
        glPushMatrix();
            glScalef(drawer_thickness/cubeSize, drawer_real_height/cubeSize, drawer_width/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
        // draw the texture for it
        glBegin(GL_QUADS);
            // draw the right(in) desk board
            glNormal3f(-1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-thickness/2-0.1, drawer_height/2 - thickness/2, +drawer_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-thickness/2-0.1, drawer_height/2 - thickness/2, -drawer_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-thickness/2-0.1, -drawer_height/2, -drawer_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-thickness/2-0.1, -drawer_height/2, +drawer_width/2);
        glEnd();

        // draw the drawer back board
        glTranslatef(-drawer_length/2, 0, -drawer_width/2);
        glPushMatrix();
            glScalef(drawer_length/cubeSize, drawer_real_height/cubeSize, drawer_thickness/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
        // draw the texture for it
        glBegin(GL_QUADS);
            // draw the back(in) desk board
            glNormal3f(0, 0, 1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-drawer_length/2, drawer_height/2, +thickness/2+0.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-drawer_length/2, -drawer_height/2, +thickness/2+0.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(+drawer_length/2-0.1, -drawer_height/2, +thickness/2+0.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(+drawer_length/2-0.1, drawer_height/2, +thickness/2+0.1);
        glEnd();

        // draw the drawer front board
        glTranslatef(0, 0, drawer_width);
        glPushMatrix();
            glScalef((drawer_length+thickness)/cubeSize, (drawer_real_height)/cubeSize, drawer_thickness/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
        // draw the texture for it
        glBegin(GL_QUADS);
            // draw the front(out) desk board
            glNormal3f(0, 0, 1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f((-drawer_length-thickness)/2, drawer_height/2 - thickness/2, +thickness/2+0.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f((-drawer_length-thickness)/2, -drawer_height/2 + thickness/2, +thickness/2+0.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f((+drawer_length+thickness)/2, -drawer_height/2 + thickness/2, +thickness/2+0.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f((+drawer_length+thickness)/2, drawer_height/2 - thickness/2 , +thickness/2+0.1);
        glEnd();

        glPushMatrix();
            glTranslatef(0, 0, drawer_thickness*2/3);
            glRotated(90, 1, 0, 0);
            glColor3f(120.0/255, 120.0/255, 120.0/255);
            glutSolidTorus(0.5, 3, 20, 20);
        glPopMatrix();

    glColor3f(1, 1, 1);
    glPopMatrix();

}

