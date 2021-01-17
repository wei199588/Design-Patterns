/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 13:44:41
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 14:09:00
 * @Description: 
 */
#include "graph.h"
void Graph::printG(int color)
{
    int i,j;
    CubePoint p;
    for(i = x; i < x+3; i++)
        for(j = y; j < y+3; j++)
        {
            if(form[i - x][j - y] == 1)
            {
                p.setLocate(i,j);
                p.setColor(color);
                p.printPoint();
            }
        }
}

int Graph::move(Direction dir)
{
    switch(dir)
    {
        case DOWN:x++;break;
        case LEFT:y--;break;
        case RIGHT:y++;break;
        default:
                break;
    }
    return 0;
}

int Graph::roll()
{
    int i,j;
    int b[3][3];
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            b[j][2-i] = form[i][j];
        }
    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
        {
            form[i][j] = b[i][j];
        }
}
