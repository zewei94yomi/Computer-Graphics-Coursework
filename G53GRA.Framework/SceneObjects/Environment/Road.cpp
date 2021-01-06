//
//  Road.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Road.hpp"


Road::Road(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z) { 
}


void Road::Display() { 
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        DrawRoad();
    glPopMatrix();
}


void Road::DrawRoad() {
    
    GLfloat road_length = 8000;
    GLfloat road_width = 500;
    GLfloat road_height = 20;
    
    GLfloat line_interval = 400;
    GLfloat line_length = 150;
    GLfloat line_width = 30;
    GLfloat line_height = 2;
    
    // draw the road
    glColor3f(105.0/255, 105.0/255, 105.0/255);
    glPushMatrix();
        glScalef(road_length, road_height, road_width);
        glutSolidCube(1);
    glPopMatrix();
    glColor3f(1, 1, 1);
    
    // draw the lines
    glColor3f(255.0/255,215.0/255,0);
    glPushMatrix();
        glTranslatef(-road_length/2 , road_height/2 + line_height/2, 0);    // go to the initial position
        for (int i = 0; i <= 20; i++) {
            glTranslatef(line_interval, 0, 0);
            glPushMatrix();
                glScalef(line_length, line_height, line_width);
                glutSolidCube(1);
            glPopMatrix();
        }
    glPopMatrix();
    glColor3f(1, 1, 1);
}
