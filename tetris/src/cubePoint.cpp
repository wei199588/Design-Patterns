/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 00:45:24
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 21:39:28
 * @Description: 
 */
#include "cubePoint.h"
void CubePoint::printPoint()
{
    Cur cur;
    cur.saveCur();
    cur.moveCur(posX,posY);
    switch(color)
    {
         case BLACK     :printf("\033[40;30m  \033[0m");break;
         case RED       :printf("\033[41;31m  \033[0m");break;
         case GREEN     :printf("\033[42;32m  \033[0m");break;
         case YELLOW    :printf("\033[43;33m  \033[0m");break;
         case BLUE      :printf("\033[44;34m  \033[0m");break;
         case PURPLE    :printf("\033[45;35m  \033[0m");break;
         case DEEP_GREEN:printf("\033[46;36m  \033[0m");break;
         case WHITE     :printf("\033[47;37m  \033[0m");break;
         case CLEAR     :printf("\033[8m  ");
         default:
         break;
    }
    cur.resumeCur();
}