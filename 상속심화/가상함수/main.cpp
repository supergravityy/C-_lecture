#include <iostream>

using namespace std;

class MyData
{
public:
	virtual void printData()
	{
		cout << "MyData::printData()" << endl;
	}

	void testFunc()
	{
		cout << "MyData::testFunc()" << endl;
		this->printData();
	}

protected:
	int m_Data = 10;
};

class MyDataEx1 : public MyData
{
public:
	virtual void printData() // 부모 메서드가 가상함수이기에, 부모메서드 인스턴스,참조형이라도 이게 불림
	{
		cout << "MyDataEx::printData()" << endl;
	}

	void testFunc()
	{
		cout << "MyDataEx::testFunc()" << endl;
		this->printData();
	}
};

int main()
{
	MyDataEx1 exp1;
	MyData& ref1 = exp1;

	exp1.printData();
	ref1.printData(); // 부모메서드가 가상함수이기에 자식의 재정의된 메서드가 불리는걸 확인가능 

	cout << "***********************************************" << endl;

	exp1.testFunc(); 
	ref1.testFunc(); // 역시 부모메서드안의 부모 가상메서드 호출이라도 자식메서드가 대신 호출됨

	return 0;
}