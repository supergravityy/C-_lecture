#include <iostream>

using namespace std;

class Parents
{
public:
	Parents()
	{
		cout << "부모 생성자" << endl;
		this->strptr = new char[31];
		strcpy_s(strptr, 31, "forTest!");
	}
	~Parents()
	{
		cout << "부모 소멸자" << endl;
		delete strptr;
	}
	void printStr()
	{
		cout << "부모 멤버 문자열 : " << strptr << endl;
	}

protected:
	char* strptr = nullptr;
};

class Child1 : public Parents
{
public:
	Child1()
	{
		cout << "자식1 생성자" << endl;
		this->strptr = nullptr;
		// 함부로 부모의 멤버값을 변경하는경우
	}
	~Child1()
	{
		cout << "자식1 소멸자" << endl;
	}
};

class Child2 : public Parents
{
public:
	Child2()
	{
		cout << "자식2 생성자" << endl;
		this->strptr = new char[32];
		// 함부로 부모의 멤버값을 초기화 하는 경우
	}
	~Child2()
	{
		cout << "자식2 소멸자" << endl;
	}
};

class Child3 : public Parents
{
public:
	Child3()
	{
		cout << "자식3 생성자" << endl;
	}
	~Child3()
	{
		cout << "자식3 소멸자" << endl;
		delete this->strptr;
		// 함부로 부모의 멤버값을 해제해버리는 경우  -> 소멸자 순서
	}
};

int main()
{
	{
		Parents pa;
		pa.printStr();
	}
	
	cout << "-------------자식2 : 함부로 부모 멤버값을 초기화 (생성자)--------------" << endl;
	{
		Child2 ch2;
		ch2.printStr();
	}
	cout << "-------------자식1 : 함부로 부모 멤버값을 변경 (생성자)--------------" << endl;
	{
		Child1 ch1;
		//ch1.printStr();
	}
	cout << "-------------자식3 : 함부로 부모 멤버값을 해제 (소멸자)--------------" << endl;
	{
		//Child3 ch3;
	}
	
}