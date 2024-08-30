#include <iostream>

using namespace std;

class Parents
{
public:
	Parents()
	{
		this->m_Data = new char[32];
	}

	~Parents() // ����ȭ �ȵ�
	{
		cout << "�θ� �Ҹ���" << endl;
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
		cout << "�ڽ� �Ҹ���" << endl;
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

	virtual ~Parents2() // �θ� �Ҹ��ڸ� �����Լ��� �����ϸ�, �ڽ� �Ҹ��ڰ� ��� ȣ�� -> �����Լ� �ּ�����
	{
		cout << "�θ�2 �Ҹ���" << endl;
		delete[] this->m_Data;
	}

	virtual void testfunc()
	{
		cout << "ȣ�⽺�� Ȯ�ο� : �θ�" << endl;
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
		cout << "�ڽ�2 �Ҹ���" << endl;
		delete[] this->m_DataEx;
	}

	void testfunc() // �θ𿡼� �����Լ��� ���� virtual�� �����, override�� virtual�� ���� �������ص� virtual�� ����
	{
		cout << "ȣ�⽺�� Ȯ�ο� : �ڽ�" << endl;
	}
private:
	int* m_DataEx = nullptr;
};

int main()
{
	Parents* Inst = new Child;
	delete Inst; // �̷��� �Ǹ�, �θ�Ҹ��ڸ� ����ǰ� �Ļ� ������ �߰��� �κ��� �޸� ������ ����

	Parents2* Inst2 = new Child2;
	Inst2->testfunc();
	delete Inst2; // �̷��� �Ǹ�, �θ�Ҹ��ڸ� ����ǰ� �Ļ� ������ �߰��� �κ��� �޸� ������ ����

	return 0;
}