/*
 * @Author: Tan Wei
 * @Date: 2021-01-15 17:08:38
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-15 17:42:37
 * @Description: 
 */

#ifndef PRODUCTA_H
#define PRODUCTA_H
#include "product.h"

class ProductA : public Product
{
public:
	void show()
	{
		cout << "I'm productA!" << endl;
	}
	
};
#endif