#include <iostream>

using namespace std;

class MyData
{
public:
	MyData()
	{
		cout << "������" << endl;
	}

	~MyData()
	{
		cout << "�Ҹ���" << endl;
	}

	void methodTest()
	{
		cout << "�޼���~~" << endl;
	}
};

int main()
{
	unique_ptr<MyData> ptrTest1(new MyData); // shared ������ó�� �������� ���� ����, �׿ܿ� �Ȱ���
	unique_ptr<MyData> ptrTest2;

	/*---------------------------------*/
	// ������Ȳ 
	// ptrTest2 = ptrTest1;
	// unique_ptr<MyData> ptrTest3(ptrTest1);
	//
	// �ٵ� ������ �̷� ��Ȳ�̶��� ���� �˾Ƹ����� ���� ���´�.....
	/*---------------------------------*/
}