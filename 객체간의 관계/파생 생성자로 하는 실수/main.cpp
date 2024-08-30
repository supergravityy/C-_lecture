#include <iostream>

using namespace std;

class Parents
{
public:
	Parents()
	{
		cout << "�θ� ������" << endl;
		this->strptr = new char[31];
		strcpy_s(strptr, 31, "forTest!");
	}
	~Parents()
	{
		cout << "�θ� �Ҹ���" << endl;
		delete strptr;
	}
	void printStr()
	{
		cout << "�θ� ��� ���ڿ� : " << strptr << endl;
	}

protected:
	char* strptr = nullptr;
};

class Child1 : public Parents
{
public:
	Child1()
	{
		cout << "�ڽ�1 ������" << endl;
		this->strptr = nullptr;
		// �Ժη� �θ��� ������� �����ϴ°��
	}
	~Child1()
	{
		cout << "�ڽ�1 �Ҹ���" << endl;
	}
};

class Child2 : public Parents
{
public:
	Child2()
	{
		cout << "�ڽ�2 ������" << endl;
		this->strptr = new char[32];
		// �Ժη� �θ��� ������� �ʱ�ȭ �ϴ� ���
	}
	~Child2()
	{
		cout << "�ڽ�2 �Ҹ���" << endl;
	}
};

class Child3 : public Parents
{
public:
	Child3()
	{
		cout << "�ڽ�3 ������" << endl;
	}
	~Child3()
	{
		cout << "�ڽ�3 �Ҹ���" << endl;
		delete this->strptr;
		// �Ժη� �θ��� ������� �����ع����� ���  -> �Ҹ��� ����
	}
};

int main()
{
	{
		Parents pa;
		pa.printStr();
	}
	
	cout << "-------------�ڽ�2 : �Ժη� �θ� ������� �ʱ�ȭ (������)--------------" << endl;
	{
		Child2 ch2;
		ch2.printStr();
	}
	cout << "-------------�ڽ�1 : �Ժη� �θ� ������� ���� (������)--------------" << endl;
	{
		Child1 ch1;
		//ch1.printStr();
	}
	cout << "-------------�ڽ�3 : �Ժη� �θ� ������� ���� (�Ҹ���)--------------" << endl;
	{
		//Child3 ch3;
	}
	
}