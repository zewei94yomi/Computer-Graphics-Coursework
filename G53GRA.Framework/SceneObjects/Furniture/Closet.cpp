//
//  Closet.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/18.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Closet.hpp"
#include <iostream>

/// initalise the closet properties
Closet::Closet(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    // tex for boards
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/closet_1.bmp");
//
//    // tex for doors
//    texID_2 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/closet_2.bmp");
    texID_1 = Scene::GetTexture("./closet_1.bmp");
    texID_2 = Scene::GetTexture("./closet_2.bmp");
}

void Closet::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(90, 0, 1, 0);
        DrawCloset();
    glPopMatrix();
}


/// update the Z rotation variable with change in time
void Closet::Update(const double& deltaTime)
{
    // animation for the closet doors
    if (opening && !closing) {
        if (yrot <= 100) {
            yrot += 50.0f * static_cast<float>(deltaTime);  // open the doors
        } else {
            yrot = 100;
            opening = false;
        }
    } else if (closing) {
        if (yrot >= 0) {
            yrot -= 50.0f * static_cast<float>(deltaTime);  // close the doors
            opening = false;
        } else {
            yrot = 0;
            closing = false;
        }
    }
}

/// set scale variables based on a key press
void Closet::HandleKey(unsigned char key, int state, int x, int y)
{
    switch (key)
    {
        case '3':
            opening = true;
            break;
        case '4':
            closing = true;
            break;
        default:
            break;
    }
}

void Closet::DrawCloset() { 
    
    // Enable Texturing
    glEnable(GL_TEXTURE_2D);

    // Enable setting the colour of the material the cube is made from
    // as well as the material for blending.
    glEnable(GL_COLOR_MATERIAL);

    // Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, texID_1);
    
    // set the size of the closet
    float thickness = 2;
    float width = 80;
    float height = 200;
    float length = 150;
    float cubeSize = 10;
    float coat_hanger_radius = 2.5;
    float coat_hanger_length = length;
    
    // start to draw the closet
    glPushMatrix();
        // draw the whole back board
        glPushMatrix();
            glBegin(GL_QUADS);
                // draw the back(out) board
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, height/2, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, -height/2, 0);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, -height/2, 0);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, height/2, 0);
                
                // draw the back(in) board
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, height/2, 0);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, height/2, 0);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, -height/2, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, -height/2, 0);
    
                // draw the left(out) board
                glNormal3f(-1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, height/2, width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, -height/2, width);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(-length/2, -height/2, 0);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(-length/2, height/2, 0);
                
                // draw the left(in) board
                glNormal3f(1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, height/2, width);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(-length/2, height/2, 0);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(-length/2, -height/2, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, -height/2, width);
    
                // draw the right(out) board
                glNormal3f(1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(length/2, height/2, width);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, height/2, 0);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, -height/2, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(length/2, -height/2, width);
    
                // draw the right(in) board
                glNormal3f(-1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(length/2, height/2, width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(length/2, -height/2, width);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, -height/2, 0);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, height/2, 0);
    
                // draw the up(out) board
                glNormal3f(0, 1, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, height/2+thickness/2+0.1, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, height/2+thickness/2+0.1, width);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, height/2+thickness/2+0.1, width);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, height/2+thickness/2+0.1, 0);
    
                //draw the up(in) board
                glNormal3f(0, -1, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, height/2-thickness/2-0.1, 0);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, height/2-thickness/2-0.1, 0);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, height/2-thickness/2-0.1, width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, height/2-thickness/2-0.1, width);
                
                // draw the down(out) board
                glNormal3f(0, -1, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, -height/2-thickness, 0);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, -height/2-thickness, 0);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, -height/2-thickness, width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, -height/2-thickness, width);
    
                // draw the down(in) board
                glNormal3f(0, 1, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(-length/2, -height/2-thickness, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-length/2, -height/2-thickness, width);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(length/2, -height/2-thickness, width);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(length/2, -height/2-thickness, 0);
            glEnd();
        glPopMatrix();
    
        // draw the up board
        glPushMatrix();
            glTranslatef(0, height/2, width/2);
            glRotated(90, 1, 0, 0);
            glScaled(length/cubeSize, width/cubeSize, thickness/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
        
        // draw the ground board
        glPushMatrix();
            glTranslatef(0, -height/2, width/2);
            glRotated(90, 1, 0, 0);
            glScaled(length/cubeSize, width/cubeSize, thickness/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
    
        // draw left door and handle:
        glPushMatrix();
            // draw left door
            glPushMatrix();
                glTranslatef(-length/2, 0, width);
                glRotatef(-yrot, 0.0f, 1.0f, 0.0f);
                glTranslatef(+length/4-0.25, 0, 0);
                glPushMatrix();
                    glScaled(length/cubeSize/2, height/cubeSize, thickness/cubeSize);
                    glutSolidCube(cubeSize);
                glPopMatrix();
    
                // Tell openGL which texture buffer to use
                glBindTexture(GL_TEXTURE_2D, texID_2);
                glBegin(GL_QUADS);
                    // draw the front left(in) board
                    glNormal3f(0, 0, -1);
                    // define texture coordinates for the 4 vertices
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex3f(-length/4, height/2, -thickness/2-0.1);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex3f(+length/4, height/2, -thickness/2-0.1);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex3f(+length/4, -height/2, -thickness/2-0.1);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex3f(-length/4, -height/2, -thickness/2-0.1);
    
                    // draw the front left(out) board
                    glNormal3f(0, 0, 1);
                    // define texture coordinates for the 4 vertices
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex3f(-length/4, height/2, +thickness/2+0.1);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex3f(-length/4, -height/2, +thickness/2+0.1);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex3f(+length/4, -height/2, +thickness/2+0.1);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex3f(+length/4, height/2, +thickness/2+0.1);
                glEnd();
    
                // draw the bar of the closet
                glPushMatrix();
                    glTranslatef(+length/6, 0, 3.5);
                    glRotated(90, 0, 1, 0);
                    glutSolidTorus(1, 5, 20, 20);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        // draw right door and handle:
        glPushMatrix();
            glTranslatef(0, 0, 0.5);
            // draw right door
            glPushMatrix();
                glTranslatef(+length/2, 0, width);
                glRotatef(yrot, 0.0f, 1.0f, 0.0f);
                glTranslatef(-length/4+0.25, 0, 0);
                glPushMatrix();
                    glScaled(length/cubeSize/2, height/cubeSize, thickness/cubeSize);
                    glutSolidCube(cubeSize);
                glPopMatrix();
    
                glBegin(GL_QUADS);
                    // draw the front right(in) board
                    glNormal3f(0, 0, -1);
                    // define texture coordinates for the 4 vertices
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex3f(-length/4, height/2, -thickness/2-0.1);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex3f(+length/4, height/2, -thickness/2-0.1);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex3f(+length/4, -height/2, -thickness/2-0.1);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex3f(-length/4, -height/2, -thickness/2-0.1);
    
                    // draw the front right(out) board
                    glNormal3f(0, 0, 1);
                    // define texture coordinates for the 4 vertices
                    glTexCoord2f(0.0f, 1.0f);
                    glVertex3f(-length/4, height/2, +thickness/2+0.1);
                    glTexCoord2f(0.0f, 0.0f);
                    glVertex3f(-length/4, -height/2, +thickness/2+0.1);
                    glTexCoord2f(1.0f, 0.0f);
                    glVertex3f(+length/4, -height/2, +thickness/2+0.1);
                    glTexCoord2f(1.0f, 1.0f);
                    glVertex3f(+length/4, height/2, +thickness/2+0.1);
                glEnd();
    
                // draw the bar of the closet
                glPushMatrix();
                    glTranslatef(-length/6, 0, 3.5);
                    glRotated(90, 0, 1, 0);
                    glutSolidTorus(1, 5, 20, 20);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    
        // Bind to the blank buffer to stop ourselves accidentaly
        // using the wrong texture in the next draw call
        glBindTexture(GL_TEXTURE_2D, NULL);
        // Stop performing texturing
        glDisable(GL_TEXTURE_2D);
    
    
        glColor3f(180.0/255, 180.0/255, 180.0/255);
        // draw the coat hanger
        glPushMatrix();
            glTranslatef(-length/2, height/3, width/2);
            glRotated(90, 0, 1, 0);
            GLUquadric *pObj = gluNewQuadric();
            gluCylinder(pObj, coat_hanger_radius, coat_hanger_radius, coat_hanger_length, 100, 100);
        glPopMatrix();

        glColor3f(139.0/255, 69.0/255, 0/255);
        // draw boards
        glPushMatrix();
            // draw the horizontal board
            glTranslatef(0, -height/4, width/2);
            glPushMatrix();
                glScaled((length-5)/cubeSize, thickness/2/cubeSize, (width-5)/cubeSize);
                glutSolidCube(cubeSize);
            glPopMatrix();
    
            // draw the vertical board
            glTranslatef(0, -height/8, 0);
            glScaled(thickness/2/cubeSize, height/4/cubeSize, width/cubeSize);
            glutSolidCube(cubeSize);
        glPopMatrix();
    glPopMatrix();
    glColor3f(1, 1, 1);
    
    // Stop blending textures and colours
    glDisable(GL_COLOR_MATERIAL);
}

