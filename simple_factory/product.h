/*
 * @Author: Tan Wei
 * @Date: 2021-01-15 17:05:04
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-15 17:41:53
 * @Description: 
 */
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

enum class productType{TYPEA, TYPEB, TYPEC};
class Product
{
public:
	virtual void show() = 0;
	
};
#endif


