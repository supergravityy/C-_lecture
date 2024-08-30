#include <iostream>

using namespace std;

class MyDataA
{
public:
	MyDataA()
	{
		cout << "MyDataA 생성자" << endl;
	}
	~MyDataA()
	{
		cout << "MyDataA 소멸자" << endl;
	}
};

class MyDataB : public MyDataA
{
public:
	MyDataB()
	{
		cout << "MyDataB 생성자" << endl;
	}
	~MyDataB()
	{
		cout << "MyDataB 소멸자" << endl;
	}
};

class MyDataC : public MyDataB
{
public:
	MyDataC()
	{
		cout << "MyDataC 생성자" << endl;
	}
	~MyDataC()
	{
		cout << "MyDataC 소멸자" << endl;
	}
};

class MyClass
{
public:
	MyClass()
	{
		cout << "부모 : default 생성자" << endl;
	}
	MyClass(int natureNum)
	{
		cout << "부모 : 정수 생성자" << endl;
	}
	MyClass(double realNum)
	{
		cout << "부모 : 실수 생성자" << endl;
	}
	~MyClass()
	{
		cout << "~부모 : 소멸자" << endl;
	}
};

class MyClassEx : public MyClass
{
public:
	MyClassEx()
	{
		cout << "자식 : default 생성자" << endl;
	}
	MyClassEx(int natureNum)
	{
		cout << "자식 : 정수 생성자" << endl;
	}
	MyClassEx(double realNum) : MyClass()
	// 실수 생성자에선 부모의 default 생성자를 호출하게 일부러 조정하였다
	// 아무것도 안쓰면, 부모의 생성자도 파라미터 형식에 맞는 생성자를 호출한다.
	{
		cout << "자식 : 실수 생성자" << endl;
	}
	~MyClassEx()
	{
		cout << "~자식 : 소멸자" << endl;
	}
};

int main()
{
	// 파생클래스의 생성/호출자의 순서를 보기 위한 코드
	{
		cout << "---------------------begin-----------------------" << endl;
		MyDataC data;
		cout << "---------------------end-------------------------" << endl;
	}
	cout << "*******************************************************" << endl;
	cout << "*******************************************************" << endl;

	{
		MyClassEx A;
		cout << "*******************************************************" << endl;
		MyClassEx B(5);
		cout << "*******************************************************" << endl;
		MyClassEx C(3.5);
	}

}