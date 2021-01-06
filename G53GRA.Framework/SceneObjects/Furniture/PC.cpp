//
//  PC.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "PC.hpp"

PC::PC(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/pc.obj");
//    texID_1 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/desktop.bmp");
    objl = new ObjLoader("./pc.obj");
    texID_1 = Scene::GetTexture("./desktop.bmp");
}

void PC::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(25, 0, 1, 0);
        glScaled(80, 80, 80);
        glColor3f(255.0/255,248.0/255,220.0/255);
        DrawPC();
        glColor3f(1, 1, 1);
    glPopMatrix();
    
    
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,texID_1);
    // bind the texture to the door
    glBegin(GL_QUADS);
        // draw the left board
        glNormal3f(0, 1, 0);
        // define texture coordinates for the 4 vertices
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(pos[0]-8, pos[1]+34, 43);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(pos[0] + 13, pos[1]+34, 33.2);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(pos[0] + 14.5, pos[1]+13, 32.7);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(pos[0]-10, pos[1]+13, 43);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, NULL);
    glDisable(GL_TEXTURE_2D);
}

void PC::DrawPC() {
    objl->Draw();

}






