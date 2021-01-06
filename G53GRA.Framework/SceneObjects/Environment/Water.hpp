//
//  Water.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/12/15.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef Water_hpp
#define Water_hpp

#include <stdio.h>
#include "DisplayableObject.h"
#include "Animation.h"
#include "Input.h"

#include <string>

#endif /* Water_hpp */

class Water :
    public DisplayableObject,
    public Animation,
    public Input
{
public:
    Water(const int& gridX, const int& gridZ);
    ~Water();

    void Display();
    void Update(const double& delteTime);
    void HandleKey(unsigned char key, int state, int x, int y);

private:
    int texID;

    int xGridDims, zGridDims;
    float* texCoords;
    double time;
    bool frozen;

    float matAmbient[4];      // matrial properties of the grid
    float matDiffuse[4];
    int   matShininess;
    float matSpecular[4];
};
