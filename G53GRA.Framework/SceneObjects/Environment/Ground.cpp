//
//  Ground.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/11.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Ground.hpp"

Ground::Ground(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
    // tex for boards
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/ground.bmp");
    texID_1 = Scene::GetTexture("./ground.bmp");
}

void Ground::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        DrawGround();
    glPopMatrix();
}

void Ground::DrawGround() {
    glPushMatrix();
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texID_1);
        
        // bind the texture to the door
        glBegin(GL_QUADS);
            // draw the left board
            glNormal3f(0, 1, 0);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 100.0f);
            glVertex3f(-10000, 0, 10000);
            glTexCoord2f(100.0f, 100.0f);
            glVertex3f(10000, 0, 10000);
            glTexCoord2f(100.0f, 0.0f);
            glVertex3f(10000, 0, -10000);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(-10000, 0, -10000);
            
        glEnd();
    
        // Stop blending textures and colours
        glDisable(GL_COLOR_MATERIAL);

        // Bind to the blank buffer to stop ourselves accidentaly
        // using the wrong texture in the next draw call
        glBindTexture(GL_TEXTURE_2D, NULL);
        
        // Stop performing texturing
        glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
