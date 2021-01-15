/*
 * @Author: Tan Wei
 * @Date: 2021-01-15 17:25:08
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-15 17:38:13
 * @Description: 
 */
#include "factory.h"

int main(int argc, char const *argv[])
{
	Factory *productFactory = new Factory();
	Product *pro;
	pro = productFactory->creatProduct(productType::TYPEA);
	pro->show();
	pro = productFactory->creatProduct(productType::TYPEB);
	pro->show();
	pro = productFactory->creatProduct(productType::TYPEC);
	pro->show();
	
	return 0;
}
