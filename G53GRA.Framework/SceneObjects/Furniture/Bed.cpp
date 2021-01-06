//
//  Bed.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/18.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Bed.hpp"
#include <iostream>

Bed::Bed(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
    // tex for boards
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/bed_board.bmp");
//    texID_2 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/bed.bmp");
    texID_1 = Scene::GetTexture("./bed_board.bmp");
    texID_2 = Scene::GetTexture("./bed.bmp");
}


void Bed::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        DrawBed();
    glPopMatrix();
}

void Bed::DrawBed() { 
    
    // Enable Texturing
    glEnable(GL_TEXTURE_2D);

    // Enable setting the colour of the material the cube is made from
    // as well as the material for blending.
    glEnable(GL_COLOR_MATERIAL);

    // Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, texID_1);
    
    // set the size of the bed
    float board_width = 10;
    float board_length = 160;
    float board_height = 100;
    
    float bed_width = 200;
    float bed_length = 150;
    float bed_height = 50;
    
    glPushMatrix();
        // draw the back
        glBegin(GL_QUADS);
            // draw the front board
            glNormal3f(0, 0, 1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-board_length/2, board_height/2, board_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-board_length/2, -board_height/2, board_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(board_length/2, -board_height/2, board_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(board_length/2, board_height/2, board_width/2);
    
            // draw the back board
            glNormal3f(0, 0, -1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-board_length/2, board_height/2, -board_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(board_length/2, board_height/2, -board_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(board_length/2, -board_height/2, -board_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-board_length/2, -board_height/2, -board_width/2);
    
            // draw the top board
            glNormal3f(0, 1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-board_length/2, board_height/2, -board_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-board_length/2, board_height/2, board_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(board_length/2, board_height/2, board_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(board_length/2, board_height/2, -board_width/2);
            
            // draw the down board
            glNormal3f(0, -1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-board_length/2, -board_height/2, -board_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(board_length/2, -board_height/2, -board_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(board_length/2, -board_height/2, board_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-board_length/2, -board_height/2, board_width/2);
    
            // draw the left board
            glNormal3f(-1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-board_length/2, board_height/2, board_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-board_length/2, board_height/2, -board_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-board_length/2, -board_height/2, -board_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-board_length/2, -board_height/2, board_width/2);
            
            // draw the right board
            glNormal3f(1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(+board_length/2, board_height/2, board_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(+board_length/2, -board_height/2, board_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(+board_length/2, -board_height/2, -board_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(+board_length/2, board_height/2, -board_width/2);
        glEnd();
    
        glTranslatef(0, -board_height/2+bed_height/2, +board_width/2+bed_width/2);
        // draw the bed
        // Tell openGL which texture buffer to use
        glBindTexture(GL_TEXTURE_2D, texID_2);
        glBegin(GL_QUADS);
            // draw the top bed
            glNormal3f(0, 1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-bed_length/2, bed_height/2, -bed_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-bed_length/2, bed_height/2, bed_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(bed_length/2, bed_height/2, bed_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(bed_length/2, bed_height/2, -bed_width/2);
    
            // draw the down bed
            glNormal3f(0, -1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-bed_length/2, -bed_height/2, -bed_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(bed_length/2, -bed_height/2, -bed_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(bed_length/2, -bed_height/2, bed_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-bed_length/2, -bed_height/2, bed_width/2);
    
            // draw the left board
            glNormal3f(-1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-bed_length/2, bed_height/2, bed_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(-bed_length/2, bed_height/2, -bed_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(-bed_length/2, -bed_height/2, -bed_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-bed_length/2, -bed_height/2, bed_width/2);
            
            // draw the right board
            glNormal3f(1, 0, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(bed_length/2, bed_height/2, bed_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(bed_length/2, -bed_height/2, bed_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(bed_length/2, -bed_height/2, -bed_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(bed_length/2, bed_height/2, -bed_width/2);
            
            // draw the front board
            glNormal3f(0, 0, 1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-bed_length/2, bed_height/2, bed_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-bed_length/2, -bed_height/2, bed_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(bed_length/2, -bed_height/2, bed_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(bed_length/2, bed_height/2, bed_width/2);
    
            // draw the back board
            glNormal3f(0, 0, -1);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(-bed_length/2, bed_height/2, -bed_width/2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(bed_length/2, bed_height/2, -bed_width/2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(bed_length/2, -bed_height/2, -bed_width/2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-bed_length/2, -bed_height/2, -bed_width/2);
        glEnd();
    
    glPopMatrix();
    
    // Stop blending textures and colours
    glDisable(GL_COLOR_MATERIAL);

    // Bind to the blank buffer to stop ourselves accidentaly
    // using the wrong texture in the next draw call
    glBindTexture(GL_TEXTURE_2D, NULL);
    // Stop performing texturing
    glDisable(GL_TEXTURE_2D);
}

