//
//  Bin.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/24.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Bin.hpp"


Bin::Bin(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/bin.obj");
    objl = new ObjLoader("./bin.obj");
}


void Bin::Display() { 
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glScaled(40, 40, 40);
        DrawBin();
    glPopMatrix();
}


void Bin::DrawBin() { 
    objl->Draw();
}
