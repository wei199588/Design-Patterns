/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 23:17:55
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 21:54:03
 * @Description: 
 */
#include "cur.h"
void Cur::saveCur()
{
	 printf("\33[s"); // 保存光标位置
}

void Cur::moveCur(const int x, const int y)
{
	int i;
	for(i = 0; i < x; i++)
        printf("\33[1B"); // 光标向下移动1
    for(i = 0; i < y; i++)
        printf("\33[2C"); // 光标向右移动2

}

void Cur::resumeCur()
{
	printf("\33[u"); // 恢复光标位置 
}