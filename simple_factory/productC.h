/*
 * @Author: Tan Wei
 * @Date: 2021-01-15 17:14:53
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-15 17:44:14
 * @Description: 
 */

#ifndef PRODUCTC_H
#define PRODUCTC_H
#include "product.h"

class ProductC : public Product
{
public:
	void show()
	{
		cout << "I'm productC!" << endl;
	}
	
};
#endif