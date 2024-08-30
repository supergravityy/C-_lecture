#include <iostream>

using namespace std;

class MyDataA
{
public:
	MyDataA()
	{
		cout << "MyDataA ������" << endl;
	}
	~MyDataA()
	{
		cout << "MyDataA �Ҹ���" << endl;
	}
};

class MyDataB : public MyDataA
{
public:
	MyDataB()
	{
		cout << "MyDataB ������" << endl;
	}
	~MyDataB()
	{
		cout << "MyDataB �Ҹ���" << endl;
	}
};

class MyDataC : public MyDataB
{
public:
	MyDataC()
	{
		cout << "MyDataC ������" << endl;
	}
	~MyDataC()
	{
		cout << "MyDataC �Ҹ���" << endl;
	}
};

class MyClass
{
public:
	MyClass()
	{
		cout << "�θ� : default ������" << endl;
	}
	MyClass(int natureNum)
	{
		cout << "�θ� : ���� ������" << endl;
	}
	MyClass(double realNum)
	{
		cout << "�θ� : �Ǽ� ������" << endl;
	}
	~MyClass()
	{
		cout << "~�θ� : �Ҹ���" << endl;
	}
};

class MyClassEx : public MyClass
{
public:
	MyClassEx()
	{
		cout << "�ڽ� : default ������" << endl;
	}
	MyClassEx(int natureNum)
	{
		cout << "�ڽ� : ���� ������" << endl;
	}
	MyClassEx(double realNum) : MyClass()
	// �Ǽ� �����ڿ��� �θ��� default �����ڸ� ȣ���ϰ� �Ϻη� �����Ͽ���
	// �ƹ��͵� �Ⱦ���, �θ��� �����ڵ� �Ķ���� ���Ŀ� �´� �����ڸ� ȣ���Ѵ�.
	{
		cout << "�ڽ� : �Ǽ� ������" << endl;
	}
	~MyClassEx()
	{
		cout << "~�ڽ� : �Ҹ���" << endl;
	}
};

int main()
{
	// �Ļ�Ŭ������ ����/ȣ������ ������ ���� ���� �ڵ�
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