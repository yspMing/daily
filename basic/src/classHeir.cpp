#include <iostream>

/*
class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() { func(); }
};

class B : public A
{
public:
	virtual void func(int val = 0) { std::cout << "B->" << val << std::endl; }
};
*/
namespace basic{

class Base
{
public:
	virtual void Func1()
	{
		std::cout << "Base::Func1()" << std::endl;
	}
	virtual void Func2()
	{
		std::cout << "Base::Func2()" << std::endl;
	}
	void Func3()
	{
		std::cout << "Base::Func3()" << std::endl;
	}

private:
	int _b = 1;
	char _c = 'a';
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		std::cout << "Derive::Func1()" << std::endl;
	}

private:
	int _d = 2;
};

void runClassHeir()
{
	Base b;
	Derive d;
	std::cout << "size of b: " << sizeof(b) << "\n";
	std::cout << "size of d: " << sizeof(d) << "\n";

	Derive s1;
	std::cout << "addr of virtual funtion 1 in s1: " << (void*)*((int64_t*)&s1) << "\n";

	Derive s2;
	std::cout << "addr of virtual funtion 1 in s2: " << (void*)*((int64_t*)&s2) << "\n";

	void* __vfptr = (void*)*((int64_t*)&s2);

	void* __vfptr0 = (void*)((int64_t*)__vfptr)[0];
	void* __vfptr1 = (void*)((int64_t*)__vfptr)[1];
	std::cout << "__vfptr0 adrr: " << __vfptr0 << "\n";
	std::cout << "__vfptr0 addr: " << __vfptr1 << "\n";
}

}