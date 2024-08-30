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

void removeArr(MyData* ptrInst)
{
	cout << "�������� �Ҵ��� �迭 ����~" << endl;

	delete[] ptrInst;
}

int main()
{
	{
		cout << "�̵�����ƽ ���� �ذ� ! ����----------------------------" << endl;
		shared_ptr<MyData> ptrTest1(new MyData);

		cout << "(����) ������ ī���Ͱ� : " << ptrTest1.use_count() << endl;
		cout << "(����) ������ �ּҰ� : " << ptrTest1.get() << endl;

		shared_ptr<MyData> ptrTest2;
		ptrTest2 = ptrTest1;	// �̵�����ƽ ���� �����

		cout << "(����) ������ ī���Ͱ� : " << ptrTest1.use_count() << endl;
		cout << "(����) ������ �ּҰ� : " << ptrTest1.get() << endl;

		shared_ptr<MyData>ptrTest3(ptrTest2); // �������� ������? (�̵�����ƽX)
		cout << "(����) ������ ī���Ͱ� : " << ptrTest1.use_count() << endl;
		cout << "(����) ������ �ּҰ� : " << ptrTest1.get() << endl;

		ptrTest1->methodTest();
		ptrTest2->methodTest();
		ptrTest3->methodTest(); // ��� �޼��� ��밡��
	}
	cout << "�̵�����ƽ ���� �ذ� ! ����----------------------------" << endl << endl;

	{
		cout << "�����迭�Ҵ� ���� �ذ� ! ���� ----------------------------" << endl;

		shared_ptr<MyData>ptrTest4(new MyData[4], removeArr); // qsort ó�� �ݹ鱸���� �迭��ü�� ����� ���Ű���
	}
	cout << "�����迭�Ҵ� ���� �ذ� ! ���� ----------------------------" << endl;
}