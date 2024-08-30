#include <iostream>

using namespace std;

class TestData
{
public:
	explicit TestData(const int data) : nData(data) // ��ȯ������ -> explicit �������� ��ȯ�� ����
	{
		cout << "TestData(int)" << endl;
	}

	TestData(const TestData& temp) : nData(temp.nData)
	{
		cout << "TestData(const TestData&)" << endl;
	}

	operator int(void) // ������ ����ȯ�Լ����� ��ȯ�� ���� �Ұ���
	// ���� �ʿ��� ������ �ν��Ͻ� ��ü�� �Ѱܵ� �����Ϸ��� �ڵ����� �� ����
	{
		return this->nData;
	}

	int getData() const
	{
		return this->nData;
	}

	void setData(const int data)
	{
		this->nData = data;
	}

private:
	int nData = 0;
};

void testFunc(const TestData &tempInst) // ���ο����� �̸����� �ӽð�ü�� ���� tempInst��� �̸��� ����
{
	cout << "testFunc() : " << tempInst.getData() << endl;
}

void print_Add(int B, int A)
{
	cout << "��������� : " << B + A << endl;
}

int main()
{
	testFunc(TestData(10)); // == testFunc(10); explicit �����ڷ� �ش� �����ڿ� ���� ���� �������� ��ȯ�� ������
	print_Add(TestData(25), 40); // ����������ȯ

	cout << "�����Լ� ����" << endl;
	return 0;
}