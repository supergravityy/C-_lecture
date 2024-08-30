#include <iostream>

using namespace std;

/*
void testFunc();

 �� �Լ��� ��¥ �̸�, �����Ϸ��� ���� ��¥ �̸���
?testFunc@@YAXXZ �̴�. 

//{
//	cout << "::testFunc()" << endl;
//}
// ��ũ������ �Ϻη� ����Ű�� ��� �����Ϸ��� �̸��� �ٲ���� �� �� �ִ�.
*/

// �׷��� �Ϻη� ���� �ͱ۸��� ���� ���� �ִ�.
// extern "C" Ű���带 ���� C�Լ�ó�� �ͱ۸��� ���ϰ� �Լ��� �̸��� ��¥ �̸��̴�.

extern "C" void testFunc()
{
	cout << "::testFunc()" << endl;
}


namespace Test
{
	void testFunc()
	{
		cout << "Test::testFunc()" << endl;
	}
}

namespace MyData
{
	void testFunc()
	{
		cout << "MyData::TestFunc()" << endl;
	}
}

int main()
{
	testFunc();
	::testFunc();
	Test::testFunc();
	MyData::testFunc();

	return 0;
}