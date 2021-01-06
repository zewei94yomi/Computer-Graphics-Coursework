//
//  Room.cpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/18.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#include "Room.hpp"

Room::Room(GLfloat x, GLfloat y, GLfloat z) : DisplayableObject(x, y, z)
{
    // tex for the room
    // paths are absolute paths
//    texID_2 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/roof.bmp");
//    texID_3 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/floor.bmp");
//    texID_4 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/door.bmp");
//    texID_5 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/draw.bmp");
//    texID_6 = Scene::GetTexture("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/Textures/win.bmp");
//    objl1 = new ObjLoader("/Users/ryan/Downloads/g53gra_framework-demo-viewing_example/G53GRA.Framework/G53GRA.Framework/obj/bar_in.obj");
    texID_2 = Scene::GetTexture("./roof.bmp");
    texID_3 = Scene::GetTexture("./floor.bmp");
    texID_4 = Scene::GetTexture("./door.bmp");
    texID_5 = Scene::GetTexture("./draw.bmp");
    texID_6 = Scene::GetTexture("./win.bmp");
    objl1 = new ObjLoader("./bar_in.obj");
}


void Room::Display() {
    glPushMatrix();
        glTranslatef(pos[0], pos[1], pos[2]);
        DrawWalls();
    glPopMatrix();
}

void Room::DrawWalls() {
    // set sizes of the room
    float room_length = 650;
    float room_width = 500;
    float room_height = 300;
    float win_left = room_length * 0.2;
    float win_ground = room_height * 0.82;
    float win_a = room_length * 0.22;
    float door_left = room_length*0.3;
    float door_height = room_height*0.8;
    float door_length = room_length*0.2;
    float window_height = win_a;
    float window_length = win_a;
    float skirting_thickness = 3;
    float skirting_height = 12;
    
    // Enable Texturing
    glEnable(GL_TEXTURE_2D);

    // Enable setting the colour of the material the cube is made from
    // as well as the material for blending.
    glEnable(GL_COLOR_MATERIAL);

    // Tell openGL which texture buffer to use
    glBindTexture(GL_TEXTURE_2D, texID_2);
    
    // draw the whole room
    glPushMatrix();
        glColor3f(1, 1, 1);
        // draw the front wall
        glPushMatrix();
            glBegin(GL_QUADS);
                // draw the front(in) board
                // upest
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 0.4f);
                glVertex3f(0, room_height, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, win_ground, 0);
                glTexCoord2f(4.0f, 0.0f);
                glVertex3f(room_length, win_ground, 0);
                glTexCoord2f(4.0f, 0.4f);
                glVertex3f(room_length, room_height, 0);
    
                // out
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(4.0f, 0.4f);
                glVertex3f(room_length, room_height, -0.1);
                glTexCoord2f(4.0f, 0.0f);
                glVertex3f(room_length, win_ground, -0.1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, win_ground, -0.1);
                glTexCoord2f(0.0f, 0.4f);
                glVertex3f(0, room_height, -0.1);

                // draw the front(in) board
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(0, win_ground, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, 0, 0);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(win_left, 0, 0);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(win_left, win_ground, 0);
    
                // out
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(win_left, win_ground, -0.1);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(win_left, 0, -0.1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, 0, -0.1);
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(0, win_ground, -0.1);
                
                // draw the front board
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 0.8f);
                glVertex3f(win_left, win_ground - win_a, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(win_left, 0, 0);
                glTexCoord2f(3.0f, 0.0f);
                glVertex3f(room_length, 0, 0);
                glTexCoord2f(3.0f, 0.8f);
                glVertex3f(room_length, win_ground - win_a, 0);
    
                // out
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(3.0f, 0.8f);
                glVertex3f(room_length, win_ground - win_a, -0.1);
                glTexCoord2f(3.0f, 0.0f);
                glVertex3f(room_length, 0, -0.1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(win_left, 0, -0.1);
                glTexCoord2f(0.0f, 0.8f);
                glVertex3f(win_left, win_ground - win_a, -0.1);
    
                // draw the front board
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(win_left + win_a, win_ground, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(win_left + win_a, win_ground - win_a, 0);
                glTexCoord2f(2.0f, 0.0f);
                glVertex3f(room_length, win_ground - win_a, 0);
                glTexCoord2f(2.0f, 1.0f);
                glVertex3f(room_length, win_ground, 0);
    
                // out
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(2.0f, 1.0f);
                glVertex3f(room_length, win_ground, -0.1);
                glTexCoord2f(2.0f, 0.0f);
                glVertex3f(room_length, win_ground - win_a, -0.1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(win_left + win_a, win_ground - win_a, -0.1);
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(win_left + win_a, win_ground, -0.1);
            glEnd();

            // draw the left wall
            glBegin(GL_QUADS);
                // draw the left(in) board
                glNormal3f(1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 2.0f);
                glVertex3f(0, room_height, room_width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, 0, room_width);
                glTexCoord2f(3.0f, 0.0f);
                glVertex3f(0, 0, 0);
                glTexCoord2f(3.0f, 2.0f);
                glVertex3f(0, room_height, 0);
    
                // draw the left(out) board
                glNormal3f(-1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(3.0f, 2.0f);
                glVertex3f(-0.1, room_height, 0);
                glTexCoord2f(3.0f, 0.0f);
                glVertex3f(-0.1, 0, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(-0.1, 0, room_width);
                glTexCoord2f(0.0f, 2.0f);
                glVertex3f(-0.1, room_height, room_width);
            glEnd();
    
            // draw the right wall
            glBegin(GL_QUADS);
                // draw the left(in) board
                glNormal3f(-1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 2.0f);
                glVertex3f(room_length, room_height, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(room_length, 0, 0);
                glTexCoord2f(3.0f, 0.0f);
                glVertex3f(room_length, 0, room_width);
                glTexCoord2f(3.0f, 2.0f);
                glVertex3f(room_length, room_height, room_width);
    
                // draw the left(out) board
                glNormal3f(1, 0, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(3.0f, 2.0f);
                glVertex3f(room_length+0.1, room_height, room_width);
                glTexCoord2f(3.0f, 0.0f);
                glVertex3f(room_length+0.1, 0, room_width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(room_length+0.1, 0, 0);
                glTexCoord2f(0.0f, 2.0f);
                glVertex3f(room_length+0.1, room_height, 0);
            glEnd();
    
            // draw the backward wall
            glBegin(GL_QUADS);
                // draw the back board
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 0.4f);
                glVertex3f(room_length, room_height, room_width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(room_length, door_height, room_width);
                glTexCoord2f(4.0f, 0.0f);
                glVertex3f(0, door_height, room_width);
                glTexCoord2f(4.0f, 0.4f);
                glVertex3f(0, room_height, room_width);
    
                // draw the back(out) board
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(4.0f, 0.4f);
                glVertex3f(0, room_height, room_width+0.1);
                glTexCoord2f(4.0f, 0.0f);
                glVertex3f(0, door_height, room_width+0.1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(room_length, door_height, room_width+0.1);
                glTexCoord2f(0.0f, 0.4f);
                glVertex3f(room_length, room_height, room_width+0.1);

                // draw the back board
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.2f);
                glVertex3f(door_left, door_height, room_width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(door_left, 0, room_width);
                glTexCoord2f(1.2f, 0.0f);
                glVertex3f(0, 0, room_width);
                glTexCoord2f(1.2f, 1.2f);
                glVertex3f(0, door_height, room_width);
    
                // draw the back(out) board
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(1.2f, 1.2f);
                glVertex3f(0, door_height, room_width+0.1);
                glTexCoord2f(1.2f, 0.0f);
                glVertex3f(0, 0, room_width+0.1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(door_left, 0, room_width+0.1);
                glTexCoord2f(0.0f, 1.2f);
                glVertex3f(door_left, door_height, room_width+0.1);
                
                // draw the back board
                // left
                glNormal3f(0, 0, -1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 2.0f);
                glVertex3f(room_length, door_height, room_width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(room_length, 0, room_width);
                glTexCoord2f(2.0f, 0.0f);
                glVertex3f(door_left + door_length, 0, room_width);
                glTexCoord2f(2.0f, 2.0f);
                glVertex3f(door_left + door_length, door_height, room_width);
    
                // draw the back(out) board
                // left
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(2.0f, 2.0f);
                glVertex3f(door_left + door_length, door_height, room_width+0.1);
                glTexCoord2f(2.0f, 0.0f);
                glVertex3f(door_left + door_length, 0, room_width+0.1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(room_length, 0, room_width+0.1);
                glTexCoord2f(0.0f, 2.0f);
                glVertex3f(room_length, door_height, room_width+0.1);
            glEnd();
    
            // Tell openGL which texture buffer to use
            glBindTexture(GL_TEXTURE_2D, texID_5);
            glBegin(GL_QUADS);
                // draw the front board
                glNormal3f(0, 0, 1);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(room_length * 0.62, win_ground * 1.1, 1);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(room_length * 0.62, win_ground * 0.6, 1);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(room_length * 0.91, win_ground * 0.6, 1);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(room_length * 0.91, win_ground * 1.1, 1);
            glEnd();

            // Tell openGL which texture buffer to use
            glBindTexture(GL_TEXTURE_2D, texID_2);

            // draw the roof
            glBegin(GL_QUADS);
                // draw the left board
                glNormal3f(0, -1, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 4.0f);
                glVertex3f(0, room_height, room_width);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, room_height, 0);
                glTexCoord2f(4.0f, 0.0f);
                glVertex3f(room_length, room_height, 0);
                glTexCoord2f(4.0f, 4.0f);
                glVertex3f(room_length, room_height, room_width);
    
                glNormal3f(0, 1, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(4.0f, 4.0f);
                glVertex3f(room_length, room_height + 0.1, room_width);
                glTexCoord2f(4.0f, 0.0f);
                glVertex3f(room_length, room_height + 0.1, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, room_height + 0.1, 0);
                glTexCoord2f(0.0f, 4.0f);
                glVertex3f(0, room_height + 0.1, room_width);
            glEnd();
    
            // Tell openGL which texture buffer to use
            glBindTexture(GL_TEXTURE_2D, texID_3);
            // draw the floor
            glBegin(GL_QUADS);
                // draw the left board
                glNormal3f(0, 1, 0);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 5.0f);
                glVertex3f(0, 0, room_width);
                glTexCoord2f(5.0f, 5.0f);
                glVertex3f(room_length, 0, room_width);
                glTexCoord2f(5.0f, 0.0f);
                glVertex3f(room_length, 0, 0);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(0, 0, 0);
            glEnd();
    
        glPopMatrix();
        glColor3f(1, 1, 1);
    
        // draw the door
        glPushMatrix();
            // Tell openGL which texture buffer to use
            glBindTexture(GL_TEXTURE_2D, texID_4);
            glTranslatef(door_left, door_height/2+2.5, room_width);
            DrawDoor(door_length, door_height, 10);
        glPopMatrix();
    
        // draw skirtings
        glPushMatrix();
            // draw the left tijiaoxian
            glPushMatrix();
                glTranslatef(skirting_thickness / 2 + 0.1, skirting_height / 2, room_width / 2);
                glScalef(skirting_thickness, skirting_height, room_width - 1);
                glutSolidCube(1);
            glPopMatrix();
    
            // draw the right tijiaoxian
            glPushMatrix();
                glTranslatef(room_length - skirting_thickness / 2 - 0.1, skirting_height / 2, room_width / 2);
                glScalef(skirting_thickness, skirting_height, room_width - 1);
                glutSolidCube(1);
            glPopMatrix();
    
            // draw the front tijiaoxian
            glPushMatrix();
                glTranslatef(room_length / 2, skirting_height / 2, skirting_thickness / 2 + 0.1);
                glScalef(room_length - 1, skirting_height, skirting_thickness);
                glutSolidCube(1);
            glPopMatrix();
    
            // draw the back_1 tijiaoxian
            glPushMatrix();
                glTranslatef(door_left / 2, skirting_height / 2, room_width - skirting_thickness / 2 - 0.1);
                glScalef(door_left - 0.11, skirting_height, skirting_thickness);
                glutSolidCube(1);
            glPopMatrix();
    
            // draw the back_2 tijiaoxian
            glPushMatrix();
                glTranslatef((door_left + door_length + room_length) / 2, skirting_height / 2, room_width - skirting_thickness / 2 - 0.1);
                glScalef(room_length - (door_left + door_length) - 0.1, skirting_height, skirting_thickness);
                glutSolidCube(1);
            glPopMatrix();
    
            // draw the window
            glPushMatrix();
                glNormal3f(0, 0, 1);
                glTranslatef(win_left, win_ground - win_a/2, 0);
                DrawWindow(window_length, window_height, 10);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    
    // Stop blending textures and colours
    glDisable(GL_COLOR_MATERIAL);

    // Bind to the blank buffer to stop ourselves accidentaly
    // using the wrong texture in the next draw call
    glBindTexture(GL_TEXTURE_2D, NULL);
    
    // Stop performing texturing
    glDisable(GL_TEXTURE_2D);

}

void Room::DrawDoor(float door_length, float door_height,  float door_width)
{
    float thickness = 5;
    glPushMatrix();
        // draw the left board
        glPushMatrix();
            glScalef(thickness, door_height, door_width);
            glutSolidCube(1);
        glPopMatrix();
    
        // draw the top board
        glPushMatrix();
            glTranslatef(door_length/2, door_height/2, 0);
            glScalef(door_length + thickness, thickness, door_width);
            glutSolidCube(1);
        glPopMatrix();
    
        // draw the right board
        glPushMatrix();
            glTranslatef(door_length, 0, 0);
            glScalef(thickness, door_height, door_width);
            glutSolidCube(1);
        glPopMatrix();
    
        // draw the ground board
        glPushMatrix();
            glTranslatef(door_length/2, -door_height/2, 0);
            glScalef(door_length + thickness, thickness, door_width);
            glutSolidCube(1);
        glPopMatrix();
    
        glPushMatrix();
            glRotated(door_rotation, 0, 1, 0);      // the door will rotate based on the rotation angle
            // draw the door
            glPushMatrix();
                glTranslatef(door_length/2, 0, 0);
                glScalef(door_length - thickness, door_height - thickness, door_width/2 );
                glutSolidCube(1);
            glPopMatrix();
            
            // bind the texture to the door
            glBegin(GL_QUADS);
                // draw the left board
                glNormal3f(0.0f, 0.0f, -1.0f);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(door_length - thickness/2, door_height/2 - thickness/2, -thickness/2 - 0.01);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(door_length - thickness/2, -door_height/2 + thickness/2, -thickness/2 - 0.01);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(thickness/2, -door_height/2 + thickness/2, -thickness/2 - 0.01);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(thickness/2, door_height/2 - thickness/2, -thickness/2 - 0.01);

                // draw the left board
                glNormal3f(0.0f, 0.0f, 1.0f);
                // define texture coordinates for the 4 vertices
                glTexCoord2f(0.0f, 1.0f);
                glVertex3f(door_length - thickness/2, door_height/2 - thickness/2, +thickness/2 + 0.01);
                glTexCoord2f(1.0f, 1.0f);
                glVertex3f(thickness/2, door_height/2 - thickness/2, +thickness/2 + 0.01);
                glTexCoord2f(1.0f, 0.0f);
                glVertex3f(thickness/2, -door_height/2 + thickness/2, +thickness/2 + 0.01);
                glTexCoord2f(0.0f, 0.0f);
                glVertex3f(door_length - thickness/2, -door_height/2 + thickness/2, +thickness/2 + 0.01);
            glEnd();
    
            // draw the inside bar
            glPushMatrix();
                glTranslatef(door_length*0.9, 5, 2);
                glRotatef(180, 0, 1, 0);
                glRotatef(lock_rotation, 0, 0, 1);
                glScaled(4, 4, 4);
                glDisable(GL_TEXTURE_2D);
                glColor3f(140.0/255, 140.0/255, 140.0/255);
                objl1->Draw();
                glEnable(GL_TEXTURE_2D);
                glColor3f(1, 1, 1);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}


void Room::DrawWindow(float window_length, float window_height, float window_width) {
    float thickness = 5;
    glPushMatrix();
        glColor3f(205.0/255, 133.0/255, 63.0/255);
        // draw the left board
        glPushMatrix();
            glScalef(thickness, window_height, window_width);
            glutSolidCube(1);
        glPopMatrix();
    
        // draw the top board
        glPushMatrix();
            glTranslatef(window_length/2, window_height/2, 0);
            glScalef(window_length + thickness, thickness, window_width);
            glutSolidCube(1);
        glPopMatrix();

        // draw the right board
        glPushMatrix();
            glTranslatef(window_length, 0, 0);
            glScalef(thickness, window_height, window_width);
            glutSolidCube(1);
        glPopMatrix();

        // draw the ground board
        glPushMatrix();
            glTranslatef(window_length/2, -window_height/2, 0);
            glScalef(window_length + thickness, thickness, window_width);
            glutSolidCube(1);
        glPopMatrix();
    
        glColor4f(238.0/255, 233.0/255, 233.0/255, 0.2);
        // draw the first glass
        glPushMatrix();
            glTranslatef(window_length / 4, 0, -2);
            glScalef(window_length / 2, window_height, window_width - 5);
            glutSolidCube(1);
        glPopMatrix();

        // draw the seconde glass
        glPushMatrix();
            glTranslatef(window_length * 3 / 4 - window_trans, 0, +2);
            glScalef(window_length / 2, window_height, window_width - 5);
            glutSolidCube(1);
        glPopMatrix();
    
        glBindTexture(GL_TEXTURE_2D, texID_6);
        glEnable(GL_BLEND);
        glColor4f(1, 1, 1, 0.2);    // windows are transparent, so we set the alpha to 0.2
        // bind the texture to the window glass
        glBegin(GL_QUADS);
            // draw the first(in) glass
            glNormal3f(0.0f, 0.0f, 1.0f);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0, window_height/2, 2);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, -window_height/2, 2);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(window_length/2, -window_height/2, 2);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(window_length/2, window_height/2, 2);

            // draw the first(out) glass
            glNormal3f(0.0f, 0.0f, -1.0f);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(window_length/2, window_height/2, -thickness+0.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(window_length/2, -window_height/2, -thickness+0.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(0, -window_height/2, -thickness+0.1);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(0, window_height/2, -thickness+0.1);
    
            // draw the second(in) glass
            glNormal3f(0.0f, 0.0f, 1.0f);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(window_length/2 - window_trans, window_height/2, thickness-0.1);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(window_length/2 - window_trans, -window_height/2, thickness-0.1);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(window_length - window_trans, -window_height/2, thickness-0.1);
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(window_length - window_trans, window_height/2, thickness-0.1);
                    
            // draw the second(out) glass
            glNormal3f(0.0f, 0.0f, -1.0f);
            // define texture coordinates for the 4 vertices
            glTexCoord2f(1.0f, 1.0f);
            glVertex3f(window_length - window_trans, window_height/2, -0.5);
            glTexCoord2f(1.0f, 0.0f);
            glVertex3f(window_length - window_trans, -window_height/2, -0.5);
            glTexCoord2f(0.0f, 0.0f);
            glVertex3f(window_length/2 - window_trans, -window_height/2, -0.5);
            glTexCoord2f(0.0f, 1.0f);
            glVertex3f(window_length/2 - window_trans, window_height/2, -0.5);
        glEnd();
        glColor4f(1, 1, 1, 1);
    glPopMatrix();
}


void Room::HandleKey(unsigned char key, int state, int x, int y) { 
    switch (key)
    {
        case '1':
            door_opening = true;
            break;
        case '2':
            door_closing = true;
            break;
        case '8':
            window_opening = true;
            break;
        case '9':
            window_closing = true;
            break;
        default:
            break;
    }
}


void Room::Update(const double &deltaTime) {
    // animation for the door
    if (door_opening && !door_closing) {
        if (door_rotation <= 90) {
            door_rotation += 2;     // rotate the door (open)
            lock_rotation += 20;    // rotate the lock
        } else {
            door_opening = false;
            door_rotation = 90;
        }
    } else if (door_closing) {
        if (door_rotation >= 0) {
            door_rotation -= 2 ;    // rotate the door (close)
            door_opening = false;   // cannot open the door now
        } else {
            door_closing = false;
            door_rotation = 0;
        }
    }
    
    // animation for the window
    if (window_opening && !window_closing) {
        if (window_trans <= 70) {
            window_trans += 2;      // transform the window (open)
        } else {
            window_opening = false;
            window_trans = 70;
        }
    } else if (window_closing) {
        if (window_trans >= 0) {
            window_trans -= 2;      // transform the window (close)
            window_opening = false;
        } else {
            window_closing = false;
            window_trans = 0;
        }
    }

}





