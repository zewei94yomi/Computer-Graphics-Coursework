//
//  Chair.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/23.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Chair.hpp"

Chair::Chair(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/chair.obj");
    objl = new ObjLoader("./chair.obj");
}

void Chair::Display()
{
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(40, 0, 1, 0);
        glScaled(100, 100, 100);
        glColor3f(160.0/255,82.0/255,45.0/255);
        DrawChair();
    glPopMatrix();
    
    glColor3f(1, 1, 1);
}

void Chair::DrawChair() { 
    objl->Draw();
}



