//
//  Clock.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/22.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Clock.hpp"
#include <math.h>
#include <time.h>

const GLfloat Pi = 3.1415926536;
const GLfloat R=50.0f;
const int n=200;
static GLfloat angle=2*Pi;
const GLfloat hour_width = R/50;
const GLfloat min_width = R/60;
const GLfloat second_width = R/70;

Clock::Clock(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
    
}


float Clock::Mysecond(struct tm *ptr)
{
    // get the angle of current second
    return ((Pi/2)-(((float)ptr->tm_sec)/60)*2*Pi);
}

float Clock::Mymin(struct tm *ptr)
{
    // get the angle of current minute
    return ((Pi/2)-((ptr->tm_min+ptr->tm_sec/60.0)/60)*2*Pi);
};

float Clock::Myhour(struct tm *ptr)
{
    // get the angle of current hour
    if(0<ptr->tm_hour&&ptr->tm_hour<12)
    {
        return ((Pi/2)-((float)ptr->tm_hour+ptr->tm_min/60.0)/12*2*Pi);
    }else{
        return ((Pi/2)-((ptr->tm_hour-12.0+ptr->tm_min/60.0)/12)*2*Pi);
    }
};

void Clock::Display()
{
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        glRotated(-90, 0, 1, 0);
        glScaled(0.5, 0.5, 0.5);
        DrawClock();
    glPopMatrix();
    
}

void Clock::Update(const double &deltaTime)
{
    // the animation of the clock is achieved by redrawing the clock, rather than rotating pointers
    // so it doesn't have implemention for animation, but it will check the current time in every frame and redraw itself
}



void Clock::DrawClock() { 
    
    struct tm *ptr;
    time_t it;
    it=time(NULL);
    ptr=localtime(&it);

    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_LINE_SMOOTH);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // Make round points, not square points
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);  // Antialias the lines
    
    glEnable(GL_COLOR_MATERIAL);
    
    glPushMatrix();
        
        glColor3f(135.0/255, 206.0/255, 250.0/255);
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*1.1*cos(2*Pi/n*i), R*1.1*sin(2*Pi/n*i), 99);
            }
        glEnd();
        
        glColor3f(1,1,1);
        
        glBegin(GL_POLYGON);
            glNormal3f(0, 0, 1);
            for(int i=0;i<n;i++)
            {
                glVertex3f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i), 100);
            }
        glEnd();
        
        glColor3f(0,0,0);
        glPointSize(100.0f);
        for(int j=0;j<12;j++)
        {
            glPushMatrix();
            glRotatef(30*j, 0, 0, 1);
            glTranslatef(0, R*3/4, 0);
            glBegin(GL_QUADS);
                glVertex3f(R/50,R/10, 105);
                glVertex3f(R/50,-R/10, 105);
                glVertex3f(-R/50,-R/10, 105);
                glVertex3f(-R/50,R/10, 105);
            glEnd();
            glPopMatrix();
        }
        
        // hour pointer
        glColor3f(0.0,0.0,0.0);
        glRotatef((angle/3600.0),0.0,0.0,1.0);
        glBegin(GL_LINES);
        glVertex3f(0.0,0.0, 105);
        glVertex3f(cos(Myhour(ptr))*R*0.45,sin(Myhour(ptr))*R*0.45, 105);
        glEnd();

        // minute pointer
        glColor3f(0.0,0.0,0.0);
        glRotatef((angle/60.0),0.0,0.0,1.0);
        glBegin(GL_LINES);
        glVertex3f(0.0,0.0, 105);
        glVertex3f(cos(Mymin(ptr))*R*0.65,sin(Mymin(ptr))*R*0.65, 105);
        glEnd();

        // second pointer
        glColor3f(0.0,0.0,0.0);
        glRotatef(angle,0.0,0.0,1.0);
        glBegin(GL_LINES);
        glVertex3f(0.0,0.0, 105);
        glVertex3f(cos(Mysecond(ptr))*R*0.85,sin(Mysecond(ptr))*R*0.85, 105);
        glEnd();
        glFlush();
        glColor3f(1,1,1);
    glPopMatrix();
}


