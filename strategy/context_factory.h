/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 17:31:13
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-16 17:41:51
 * @Description: 
 */
#pragma once
#include "abstractCout.h"
#include "coutA.h"
#include "coutB.h"
#include "coutC.h"
enum class typeCout{COUTA, COUTB, COUTC};

class ContextFactory
{	
public:
	ContextFactory(typeCout tc) 
	{
		switch (tc)
		{
		case typeCout::COUTA:
			pAbsCout = new CoutA();
			break;
		case typeCout::COUTB:
			pAbsCout = new CoutB();
			break;
		case typeCout::COUTC:
			pAbsCout = new CoutC();
			break;
		
		default:
			break;
		}

	}
	void ContextFactoryInterface()
	{
		pAbsCout->interface();
	}
	
	

private:
	AbstractCout *pAbsCout;
};


