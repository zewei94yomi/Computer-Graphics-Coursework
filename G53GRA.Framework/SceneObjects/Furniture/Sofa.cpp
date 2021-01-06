//
//  Sofa.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/16.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Sofa.hpp"

Sofa::Sofa(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/sofa.obj");
    objl = new ObjLoader("./sofa.obj");
}

void Sofa::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(90, 0, 1, 0);
        glPushMatrix();
            glScalef(120, 160, 120);
            glEnable(GL_COLOR_MATERIAL);
            glColor3f(205.0/255, 170.0/255, 125.0/255);
            DrawSofa();
            glColor3f(1, 1, 1);
        glPopMatrix();
    glPopMatrix();
}

void Sofa::DrawSofa() {
    objl->Draw();
}
