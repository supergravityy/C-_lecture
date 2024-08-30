#include <iostream>

using namespace std;

void exceptTest1()
{
	int input;
	cout << "1~10 양의 정수 입력 : ";
	cin >> input;

	if (input < 1 || input > 10)
		throw input;
}

void exceptTest2()
{
	char ch;
	cout << "메뉴 : [A]dd\t[D]elete\t[E]xit\n" << endl;
	cin >> ch;

	if (ch != 'A' && ch != 'D' && ch != 'E')
		throw ch;
}

void exceptTest3()
{
	throw 0.05;
}

int main()
{
	try
	{
		exceptTest1();
		exceptTest2();
		exceptTest3();
	}
	catch (int input)
	{
		cout << "Err : " << input << "는 범위를 벗어난 숫자입니다" << endl;
	}
	catch (char ch)
	{
		cout << "Err : " << ch << "는 알 수 없는 메뉴입니다" << endl;
	}
	catch (...)
	{
		cout << "Err : 일부러 오류냄" << endl;
	}

	return 0;
}