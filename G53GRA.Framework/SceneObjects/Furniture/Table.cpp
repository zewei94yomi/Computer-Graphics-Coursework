//
//  Table.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/16.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Table.hpp"

Table::Table(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/table.obj");
    objl = new ObjLoader("./table.obj");
}

void Table::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(90, 0, 1, 0);
        glPushMatrix();
            glScalef(35, 35, 35);
            glEnable(GL_COLOR_MATERIAL);
            glColor4f(0.5, 0.5, 0.5, 0.65);
            DrawTable();
            glColor4f(1, 1, 1, 1);
        glPopMatrix();
    glPopMatrix();
}

void Table::DrawTable() {
    objl->Draw();
}
