/*
 * @Author: Tan Wei
 * @Date: 2021-01-15 17:15:58
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-15 17:45:20
 * @Description: 
 */
#ifndef FACTORY_H
#define FACTORY_H
#include "productA.h"
#include "productB.h"
#include "productC.h"
class Factory
{
public:
	Product* creatProduct(productType pType)
	{
		switch (pType)
		{
		case productType::TYPEA:
			return new ProductA();
			break;
		case productType::TYPEB:
			return new ProductB();
			break;
		case productType::TYPEC:
			return new ProductC();
			break;
		
		default:
			return NULL;
			break;
		}
	}
};
#endif