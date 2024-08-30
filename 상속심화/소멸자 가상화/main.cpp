#include <iostream>

using namespace std;

class Parents
{
public:
	Parents()
	{
		this->m_Data = new char[32];
	}

	~Parents() // 가상화 안됨
	{
		cout << "부모 소멸자" << endl;
		delete[] this->m_Data;
	}
private:
	char* m_Data = nullptr;
};

class Child : public Parents
{
public:
	Child()
	{
		this->m_DataEx = new int;
	}

	~Child()
	{
		cout << "자식 소멸자" << endl;
		delete[] this->m_DataEx;
	}
private:
	int* m_DataEx = nullptr;
};

class Parents2
{
public:
	Parents2()
	{
		this->m_Data = new char[32];
	}

	virtual ~Parents2() // 부모 소멸자를 가상함수로 설정하면, 자식 소멸자가 대신 호출 -> 메인함수 주석참조
	{
		cout << "부모2 소멸자" << endl;
		delete[] this->m_Data;
	}

	virtual void testfunc()
	{
		cout << "호출스택 확인용 : 부모" << endl;
	}

private:
	char* m_Data = nullptr;
};

class Child2 : public Parents2
{
public:
	Child2()
	{
		this->m_DataEx = new int;
	}

	~Child2()
	{
		cout << "자식2 소멸자" << endl;
		delete[] this->m_DataEx;
	}

	void testfunc() // 부모에서 가상함수를 위해 virtual을 선언시, override로 virtual을 빼고 재정의해도 virtual이 생김
	{
		cout << "호출스택 확인용 : 자식" << endl;
	}
private:
	int* m_DataEx = nullptr;
};

int main()
{
	Parents* Inst = new Child;
	delete Inst; // 이렇게 되면, 부모소멸자만 실행되고 파생 형식의 추가된 부분은 메모리 누수로 남음

	Parents2* Inst2 = new Child2;
	Inst2->testfunc();
	delete Inst2; // 이렇게 되면, 부모소멸자만 실행되고 파생 형식의 추가된 부분은 메모리 누수로 남음

	return 0;
}