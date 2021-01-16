/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 16:33:46
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-16 16:47:15
 * @Description: 
 */
#pragma once
#include "abstractCout.h"

class CoutA : public AbstractCout
{
public:
	void interface() override
	{
		cout << "I'm from concret A!" << endl;
	}
};