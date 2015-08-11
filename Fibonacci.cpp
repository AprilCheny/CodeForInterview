#include <iostream>

using namespace std;

class Test1 //������Ҫ�����ڴ棨ʵ�����������sizeofΪ1
{
public:
	Test1(){}
	~Test1(){}
};

class Test2
{
public:
	Test2(int i = 0, char c = '0') : iv(i), ch(c) //���졢����������sizeof�޹�
	{
		//const��Ա����ֻ���ڹ��캯����ʼ���б���г�ʼ��
		//iv = i; //const��Ա���������ڹ��캯�����ڳ�ʼ��
	}
	~Test2(){}

	virtual void funa() //����麯��ֻ��һ�����ָ�룬4Byte(32λϵͳ)
	{
		cout << "funa()" << endl;
	}
	virtual void funb()
	{
		cout << "funb()" << endl;
	}
	void func() //��ͨ��Ա����Ϊ��ʵ�����У�������sizeof
	{
		cout << "func()" << endl;
	}
	static void fund() //static��Ա����������sizeof
	{
		cout << "fund()" << endl;
	}
	static int si; //static��Ա����������sizeof
	static int* sip; //staticָ���Ա����������sizeof

private:
	const int iv; //4Byte(32λϵͳ)
	char ch; //���룬4Byte
	double* dp; //ָ�룬4Byte(32λϵͳ)
};

int Test2::si = 1; //static��Ա������ʼ��
int* Test2::sip = &Test2::si;

class Test3
{
public:
	Test3(int i) : iv(i){}
	Test3()
	{
		Test3(1); //���ܰ�Ԥ����ȷ��ʼ��iv=1����ʱ������������һ����ʱ����
	}

	int iv;
};

class Test4
{
public:
	Test4(int i) : iv(i){}
	Test4()
	{
		new (this) Test4(1); //placement new���������԰�Ԥ����ȷ��ʼ��iv=1
		//placement new��������ʽ�� new(void *p) Type(...)����ʾ��p��ָ���ڴ��������Type���캯�����ù���û���ڴ�����
	}

	int iv;
};

class Test5
{
public:
	Test5(int i) : iv(i){}
	Test5() : Test5(1){} //�����ڹ��캯����ʼ���б�ֱ�ӵ�����һ���캯������Ԥ����ȷ��ʼ��iv=1

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
	cout << "Test1 size: " << sizeof(Test1) << ", test size: " << sizeof(test1) << endl; //sizeof���ʵ������
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