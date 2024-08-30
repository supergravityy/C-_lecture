#include <iostream>

using namespace std;

void testFunc1()
{
	cout << "testFunc1() - 시작" << endl;
	throw 0;
	cout << "testFunc1() - 종료" << endl;
}

void testFunc2()
{
	cout << "testFunc2() - 시작" << endl;
	testFunc1();
	cout << "testFunc2() - 종료" << endl;
}

void testFunc3()
{
	cout << "testFunc3() - 시작" << endl;
	testFunc2();
	cout << "testFunc3() - 종료" << endl;
}

void testFunc4()
{
	cout << "testFunc4() - 시작" << endl;
	testFunc3();
	cout << "testFunc4() - 종료" << endl;
}

// 콜 스택구조 : 원점 -> tF4 -> tF3 -> tF2 -> tF1

int main()
{
	try
	{
		testFunc4();
	}
	catch (...)
	{
		cout << "오류발생!" << endl;
	}

	return 0;
}