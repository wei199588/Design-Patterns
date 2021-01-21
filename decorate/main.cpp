/*
 * @Author: Tan Wei
 * @Date: 2021-01-21 22:53:21
 * @LastEditors: Tan Wei
 * @LastEditTime: 2021-01-21 23:42:38
 * @Description: 
 */
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void show() = 0;
};

class BaseC :public Base
{
public:
	 void show()
	 {
		 cout << "BaseC" << endl;
	 }
};
class Deco : public Base
{
public:
	Deco(Base* base) : base_(base){}
	void show()
	{
		base_->show();
	
		makeUp();
		
	}
	virtual void makeUp() = 0;
protected:
	Base* base_;
};

class Deco1 : public Deco
{
public:
	Deco1(Base* base) : Deco(base){}
	// void show()
	// {
	// 	cout << "Deco1" << endl;
	// }
	void makeUp()
	{
		cout << "11" <<endl;
	}
};
class Deco2 : public Deco
{
public:
	Deco2(Base* base) : Deco(base){}
	// void show()
	// {
	// 	cout << "Deco2" << endl;
	// }
	void makeUp()
	{
		cout << "22" <<endl;
	}
};

int main(int argc, char const *argv[])
{
	Base *p = new BaseC();
	Deco1 *p1 = new Deco1(p);
	Deco2 *p2 = new Deco2(p1);
	p2->show();
	return 0;
}
