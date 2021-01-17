/*
 * @Author: Tan Wei
 * @Date: 2021-01-17 16:21:34
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-17 21:33:19
 * @Description: 
 */
#include "score.h"
#include "cur.h"
#include "cubePoint.h"

void Score::printMessage()
{
   Cur c;
   CubePoint p;

   p.setLocate(2,19);
   p.setColor(WHITE);
   p.printPoint();
   //c.saveCur();
   c.resumeCur();
   c.moveCur(2,21);
   cout<<"player: "<<player_;
   c.resumeCur();
   p.setLocate(4,19);
   p.setColor(GREEN);
   p.printPoint();
   //c.saveCur();
   c.resumeCur();
   c.moveCur(4,21);
   cout<<"score : "<<score_;
   c.resumeCur();

}
