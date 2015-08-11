#include <iostream>

using namespace std;

class Test1 //空类需要分配内存（实例化），因此sizeof为1
{
public:
	Test1(){}
	~Test1(){}
};

class Test2
{
public:
	Test2(int i = 0, char c = '0') : iv(i), ch(c) //构造、析构函数与sizeof无关
	{
		//const成员变量只能在构造函数初始化列表进行初始化
		//iv = i; //const成员变量不能在构造函数体内初始化
	}
	~Test2(){}

	virtual void funa() //多个虚函数只需一个虚表指针，4Byte(32位系统)
	{
		cout << "funa()" << endl;
	}
	virtual void funb()
	{
		cout << "funb()" << endl;
	}
	void func() //普通成员函数为各实例共有，不计入sizeof
	{
		cout << "func()" << endl;
	}
	static void fund() //static成员函数不计入sizeof
	{
		cout << "fund()" << endl;
	}
	static int si; //static成员变量不计入sizeof
	static int* sip; //static指针成员变量不计入sizeof

private:
	const int iv; //4Byte(32位系统)
	char ch; //对齐，4Byte
	double* dp; //指针，4Byte(32位系统)
};

int Test2::si = 1; //static成员变量初始化
int* Test2::sip = &Test2::si;

class Test3
{
public:
	Test3(int i) : iv(i){}
	Test3()
	{
		Test3(1); //不能按预想正确初始化iv=1，此时编译器生成了一个临时对象
	}

	int iv;
};

class Test4
{
public:
	Test4(int i) : iv(i){}
	Test4()
	{
		new (this) Test4(1); //placement new技术，可以按预想正确初始化iv=1
		//placement new技术的形式是 new(void *p) Type(...)，表示在p所指的内存区域调用Type构造函数，该过程没有内存请求
	}

	int iv;
};

class Test5
{
public:
	Test5(int i) : iv(i){}
	Test5() : Test5(1){} //可以在构造函数初始化列表直接调用另一构造函数，按预想正确初始化iv=1

	int iv;
};

__int64 Fibonacci1(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}

__int64 Fibonacci2(unsigned int n)
{
	if (n <= 0)
		return 0;
	if (n == 1)
		return 1;

	__int64 fibN0 = 0;
	__int64 fibN1 = 1;
	__int64 fibN2 = 0;
	for (unsigned int i = 2; i <= n; ++i)
	{
		fibN0 = fibN1 + fibN2;
		fibN2 = fibN1;
		fibN1 = fibN0;
	}

	return fibN0;
}

__int64 Fibonacci3(unsigned int n)
{
	return 0;
}

int main()
{
	Test1 test1;
	cout << "Test1 size: " << sizeof(Test1) << ", test size: " << sizeof(test1) << endl; //sizeof针对实例而言
	Test2 test2;
	cout << "Test2 size: " << sizeof(Test2) << ", test size: " << sizeof(test2) << endl;
	Test3 test3;
	cout << "Test3 init: " << test3.iv << endl;
	Test4 test4;
	cout << "Test4 init: " << test4.iv << endl;
	Test5 test5;
	cout << "Test5 init: " << test5.iv << endl;

	const unsigned int num = 5;
	__int64 res1 = Fibonacci1(num);
	__int64 res2 = Fibonacci2(num);
	__int64 res3 = Fibonacci3(num);
	cout << res1 << " " << res2 << " " << res3 << endl;

	return 0;
}