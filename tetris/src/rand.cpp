/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 16:29:56
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 16:32:03
 * @Description: 
 */
#include "rand.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
using namespace std;

//使用随机数的一个错误的方式就是每次都去srand,这样当多次调用很接近时值就会
//一样（和时间关系很大）而srand一次就不存在这个问题了。
Rand::Rand()
{
    srand(unsigned(time(0)));
}

double random(double start,double end)
{
    return start + (end - start)*rand()/(RAND_MAX + 1.0);
}

int Rand::randNum(int x,int y)
{
    int randNum;
    //double random(double,double);
    randNum = int(random(x,y));
    return randNum;
}

