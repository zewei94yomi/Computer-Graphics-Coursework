//
//  Light.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Light.hpp"

Light::Light(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
//    objl = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/light.obj");
//    objl = new ObjLoader("../G53GRA.Framework/obj/light.obj");
    objl = new ObjLoader("./light.obj");
}

void Light::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(180, 0, 0, 1);
        glScalef(5, 5, 5);
        glColor4f(250.0/255,250.0/255,210.0/255, 0.6);
        DrawLight();
        glColor4f(1, 1, 1, 1);
    glPopMatrix();
}

void Light::DrawLight() {
    objl->Draw();
}
