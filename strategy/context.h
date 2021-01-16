/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 16:39:22
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-16 16:46:33
 * @Description: 
 */
#pragma once
#include "abstractCout.h"
#include "coutA.h"
#include "coutB.h"
#include "coutC.h"
class Context
{
public:
	Context(AbstractCout *pAbsCoutArg): pAbsCout(pAbsCoutArg){}
	
	void contextInterface()
	{
		pAbsCout->interface();
	}
private:
	AbstractCout *pAbsCout;
};