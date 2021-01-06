#include "MyScene.h"
#include "Room.hpp"
#include "Bed.hpp"
#include "Closet.hpp"
#include "Desk.hpp"
#include "Clock.hpp"
#include "Chair.hpp"
#include "PC.hpp"
#include "Pillow.hpp"
#include "Bin.hpp"
#include "Fan.hpp"
#include "Ball.hpp"
#include "BouncingBall.hpp"
#include "Dart.hpp"
#include "DartBoard.hpp"
#include "Ground.hpp"
#include "Building.hpp"
#include "Skybox.hpp"
#include "Light.hpp"
#include "Road.hpp"
#include "Plane.hpp"
#include "Water.hpp"
#include "Boat.hpp"
#include "Table.hpp"
#include "Sofa.hpp"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight){}

void MyScene::Initialise()
{
	// set the background colour of the scene to black
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    // Create scene objects
    Skybox * sb = new Skybox(GetCamera());
    Room *r = new Room(0, 0, 0);
    Bed *b = new Bed(500, 50, 9);
    Desk *d = new Desk(250, 100, 40);
    Closet *c = new Closet(4, 101, 250);
    Clock *cc = new Clock(697, 200, 250);
    Chair *chair = new Chair(280, 0, 150);
    PC* pc = new PC(220, 102, 33);
    Pillow * pillow = new Pillow(500, 50, 25);
    Bin * bin = new Bin(600, 0, 450);
    Fan * fan = new Fan(420, 280, 220);
    Ball * ball = new Ball(370, 125, 50);
    BouncingBall *bouncingball = new BouncingBall(500, 15, 250);
    Dart * dart = new Dart(312, 104, 44, 420, 190, 467);
    DartBoard * dartBoard = new DartBoard(420, 190, 549);
    Ground * ground = new Ground(0, -0.2, 0);
    Building * building = new Building(-400, 0, 300);
    Light * light = new Light(280, 300, 220);
    Road * road = new Road(0, 0, 1000);
    Plane * plane = new Plane(-1500, 10, 1000);
    Water * water = new Water(300, 20);
    water->position(-3000, 1, -600);
    water->size(400.0f);
    Boat * boat = new Boat(-1000, 50, -350);
    Table * table = new Table(375, 10, 50);
    Sofa * sofa = new Sofa(420, 0, 467);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    // add objects to the scene
    AddObjectToScene(sofa);
    AddObjectToScene(boat);
    AddObjectToScene(water);
    AddObjectToScene(sb);
    AddObjectToScene(ground);
    AddObjectToScene(b);
    AddObjectToScene(c);
    AddObjectToScene(d);
    AddObjectToScene(cc);
    AddObjectToScene(chair);
    AddObjectToScene(pc);
    AddObjectToScene(pillow);
    AddObjectToScene(bin);
    AddObjectToScene(fan);
    AddObjectToScene(ball);
    AddObjectToScene(bouncingball);
    AddObjectToScene(dart);
    AddObjectToScene(dartBoard);
    AddObjectToScene(building);
    AddObjectToScene(light);
    AddObjectToScene(road);
    AddObjectToScene(plane);
    AddObjectToScene(r);
    AddObjectToScene(table);
}

/// set the perspective of camera
void MyScene::Projection()
{
    GLdouble aspect = static_cast<GLdouble>(windowWidth) / static_cast<GLdouble>(windowHeight);
    gluPerspective(60.0, aspect, 1.0, 9000.0); // the last parameter set the field of vision
}

