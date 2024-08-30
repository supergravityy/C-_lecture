#include<iostream>

using namespace std;

class Test1
{
public:
	Test1()
	{
		// ���Ĵٵ��� �Լ�������
		data1 = 10;
		data2 = 20;
		cout << "Test1 ������" << endl;
	}

	int data1, data2;

	void printData()
	{
		cout << data1 << data2 << endl;
	}

	~Test1()
	{
		cout << "Test1 ������" << endl;
	}
};

class Test2
{
public:
	Test2() : data1(10), data2(20)
	{
		data1 = 20;
		data2 = 30;
		cout << "Test2 ������" << endl;
		// C++�� �Ǵٸ� ������ ������ -> �򰥸��� ����
		// C++���� ��ȣ���� �������� �����.
	}

	int data1, data2 = 30;

	void printData()
	{
		cout << data1 << data2 << endl;
	}

	~Test2()
	{
		cout << "Test2 ������" << endl;
	}
};

class Test3
{
public:
	// �����ڴ� �������� ���ǰ� �����ϴ�

	Test3() = default; 
	// default �����ڴ� �ƹ��͵� ���� -> �Ϻη� ����,���ǵ��� ���ϴ� �͵� ����

	Test3(int& param) : member(param)
	// �ܺκ����� ������ �� �ְ��ϴ� �����ڸ� ����� ������
	
	// �� �ν��Ͻ��� �������ڸ��� Ŭ������ �����ڰ� ���� �� �ʱ�ȭ�� ����Ǿ�� �ϱ⿡, �̷��� �������ιۿ� ������ �ȵȴ�.
	// �׷��⿡, �ܺκ����� �����Ϸ��� ������ ��ſ� �����Ͱ� �� �����ϴ�
	{} 

	int& member; // int �� �����ڷ� ���� -> �ܺκ����� ���ٰ���

	void changing()
	{
		member = 50;
	}

	~Test3()
	{}
};

int main()
{
	cout << "�����Լ� �����" << endl;
	Test1* test1 = new Test1();
	Test2 test2;

	test1->printData(); // �����ͷ� �����߱⿡ ����ü�� �Ȱ��� ���ٹ���� ����
	test2.printData();

	int data = 5;
	cout << "�ٲٱ����� �������� data : " << data << endl;
	
	Test3 test3(data); // ���� data ������ Ŭ���� ����� �����
	test3.changing();
	cout << "�ٲ����� �������� data : " << data << endl;


	delete test1;

	cout << "�����Լ� �����" << endl;
	// �����Լ��� ����ǰ� �Ҹ��ڰ� ������� �� �����ش�.
}