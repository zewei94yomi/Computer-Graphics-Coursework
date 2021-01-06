//
//  TestCube.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/18.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef TestCube_hpp
#define TestCube_hpp

#include <stdio.h>

#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#endif /* TestCube_hpp */

class TestCube :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    TestCube();
    ~TestCube(){};

    void Display();
    void Update(const double& deltaTime);
    void HandleKey(unsigned char key, int state, int x, int y);

    void HandleSpecialKey(int key, int state, int x, int y){}
    void HandleMouse(int button, int state, int x, int y){}
    void HandleMouseDrag(int x, int y){}
    void HandleMouseMove(int x, int y){}

private:
    float xrot, yrot, zrot;
    float scale;
};
