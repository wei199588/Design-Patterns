/*
 * @Author: Tan Wei
 * @Date: 2021-01-15 17:14:25
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-15 17:43:18
 * @Description: 
 */

#ifndef PRODUCTB_H
#define PRODUCTB_H
#include "product.h"

class ProductB : public Product
{
public:
	void show()
	{
		cout << "I'm productB!" << endl;
	}
	
};
#endif