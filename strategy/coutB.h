/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 16:38:28
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-16 16:47:27
 * @Description: 
 */
#pragma once
#include "abstractCout.h"

class CoutB : public AbstractCout
{
public:
	void interface() override
	{
		cout << "I'm from concret B!" << endl;
	}
};