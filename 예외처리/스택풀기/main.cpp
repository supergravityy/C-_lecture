#include <iostream>

using namespace std;

void testFunc1()
{
	cout << "testFunc1() - ����" << endl;
	throw 0;
	cout << "testFunc1() - ����" << endl;
}

void testFunc2()
{
	cout << "testFunc2() - ����" << endl;
	testFunc1();
	cout << "testFunc2() - ����" << endl;
}

void testFunc3()
{
	cout << "testFunc3() - ����" << endl;
	testFunc2();
	cout << "testFunc3() - ����" << endl;
}

void testFunc4()
{
	cout << "testFunc4() - ����" << endl;
	testFunc3();
	cout << "testFunc4() - ����" << endl;
}

// �� ���ñ��� : ���� -> tF4 -> tF3 -> tF2 -> tF1

int main()
{
	try
	{
		testFunc4();
	}
	catch (...)
	{
		cout << "�����߻�!" << endl;
	}

	return 0;
}