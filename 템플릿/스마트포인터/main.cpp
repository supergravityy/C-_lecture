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
};

void testFunc()
{
	cout << "*****testFunc ����*****" << endl;
	auto_ptr<MyData> ptrTest1(new MyData);
	cout << "*****testFunc ����*****" << endl;

	// ���� : auto_ptr <������ ����> �ν��Ͻ��̸�(�����Ҵ� ����);
}

int main()
{
	testFunc();

	cout << "*****������1 ����*****" << endl;
	{
		auto_ptr<MyData> ptrTest2(new MyData);
		auto_ptr<MyData> ptrTest3;

		// ������ 1. ���⼭ ���Կ����ڴ� �̵�����ƽ ���� ���� -> ���� �򰥸�
		cout << "ptrTest2 �������ּ� : 0x" << ptrTest2.get() << endl;
		ptrTest3 = ptrTest2;
		// Ȥ�ö� ptrTest2�� MyData �޼��带 ���� �ٷ� Heap ���� �߻�!
		cout << "ptrTest2 �������ּ� : 0x" << ptrTest2.get() << endl;
	}
	cout << "*****������1 ����*****" << endl;

	cout << "*****������2 ����*****" << endl;
	{
		// ������ 2. �迭�� �����, �Ҹ��Ҷ�, �ϳ��� ���� -> ���� ���⼭ ������ 2���� ��� ���� -> �޸� ����
		auto_ptr<MyData> ptrTest4(new MyData[3]);
		// �̴� auto_ptr�� �Ҹ��ڰ� delete[] �� ���� �ʱ� ����!!!!!
	}
	cout << "*****������2 ����*****" << endl;
}
