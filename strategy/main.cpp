/*
 * @Author: Tan Wei
 * @Date: 2021-01-16 16:47:55
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-16 17:49:33
 * @Description: 
 */
//只是策略模式会发现客户端要写很多判断，耦合度高
#if 0
#include "context.h"
// #include <string>
int main(int argc, char const *argv[])
{
	cout << "please choose type cout:" << endl;
	cout << "1 : coutA" << endl;
	cout << "2 : coutB" << endl;
	cout << "3 : coutC" << endl;
	int input;
	cin >> input;
	Context *context = NULL;
	switch (input)
	{
	case 1:
		context = new Context(new CoutA()); 
		context->contextInterface();
		break;
	case 2:
		context = new Context(new CoutB()); 
		context->contextInterface();
		break;
	case 3:
		context = new Context(new CoutC()); 
		context->contextInterface();
		break;
	default:
		break;
	}
	return 0;
}
#endif
// ----------------------------------
// 策略模式和简单工厂模式结合
#if 1
#include "context_factory.h"
int main(int argc, char const *argv[])
{
	ContextFactory cfA(typeCout::COUTA);
	cfA.ContextFactoryInterface();
	// ContextFactory cfB(typeCout::COUTB);
	// cfB.ContextFactoryInterface();
	// ContextFactory cfC(typeCout::COUTC);
	// cfC.ContextFactoryInterface();
	
	return 0;
}


#endif