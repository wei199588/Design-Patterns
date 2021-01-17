/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 22:47:31
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 01:10:11
 * @Description: 光标移动类
 */
#ifndef CUR_H
#define CUR_H
#include <iostream>
using namespace std;
class Cur
{
public:
	void saveCur();
	void moveCur(const int x, const int y);
	void resumeCur(); //恢复光标位置
};
#endif
