//
//  Pillow.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Pillow.hpp"


Pillow::Pillow(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/pillow.obj");
    objl = new ObjLoader("./pillow.obj");
}

void Pillow::Display()
{
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(30, 1, 0, 0);
        glScaled(70, 60, 60);
        DrawPillow();
    glPopMatrix();
}

void Pillow::DrawPillow() {
    objl->Draw();
}
