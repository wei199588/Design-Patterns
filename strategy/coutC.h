/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 16:38:55
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-16 16:39:04
 * @Description: 
 */
#pragma once
#include "abstractCout.h"

class CoutC : public AbstractCout
{
public:
	void interface() override
	{
		cout << "I'm from concret C!" << endl;
	}
};