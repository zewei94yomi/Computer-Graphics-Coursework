//
//  ObjLoader.hpp
//  G53GRA.Framework
//
//  Created by 周泽炜 on 2020/11/23.
//  Copyright © 2020 w.o.c.ward. All rights reserved.
//

#ifndef ObjLoader_hpp
#define ObjLoader_hpp

#pragma once
#include <stdio.h>
#include <vector>
#include <iostream>
#include <GLUT/GLUT.h>
#endif /* ObjLoader_hpp */
using namespace std;


class ObjLoader
{
public:
    ObjLoader(string filename);//读取函数
    void Draw();//绘制函数
private:
    vector<vector<GLfloat>>vSets;   // 顶点
    vector<vector<GLfloat>>vnSets;  // 法向量
    vector<vector<GLfloat>>vtSets;  // 纹理坐标
    vector<vector<GLint>>fSets; // 面
};
