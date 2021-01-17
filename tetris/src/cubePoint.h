/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 00:33:14
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 18:01:21
 * @Description: 
 */
#ifndef CUBEPOINT_H_
#define CUBEPOINT_H_
#include<iostream>
#include "cur.h"
using namespace std;

enum Color{
    CLEAR = 0,
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    DEEP_GREEN,
    WHITE	
};

class CubePoint
{
private:
	int color;
	int posX;
	int posY;
	
public:
	CubePoint()
	{
		color = CLEAR;
		posX = 0;
		posY = 0;
	}
	CubePoint(int myColor, int myPosX, int myPosY) : color(myColor), posX(myPosX), posY(myPosY){} 
	
	void setLocate(const int x,const int y){this->posX= x;this->posY = y;}
    void setColor(const int color){this->color = color;}
                                                                                                                                                                                                           
    int getColor(){return color;}
    void getLocate(int&x,int &y){x = this->posX;y = this->posY;}
    //打印点的方法
    void printPoint();
};


#endif