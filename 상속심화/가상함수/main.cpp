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
	virtual void printData() // �θ� �޼��尡 �����Լ��̱⿡, �θ�޼��� �ν��Ͻ�,�������̶� �̰� �Ҹ�
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
	ref1.printData(); // �θ�޼��尡 �����Լ��̱⿡ �ڽ��� �����ǵ� �޼��尡 �Ҹ��°� Ȯ�ΰ��� 

	cout << "***********************************************" << endl;

	exp1.testFunc(); 
	ref1.testFunc(); // ���� �θ�޼������ �θ� ����޼��� ȣ���̶� �ڽĸ޼��尡 ��� ȣ���

	return 0;
}