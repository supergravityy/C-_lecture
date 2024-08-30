#include <iostream>

using namespace std;

void exceptTest1()
{
	int input;
	cout << "1~10 ���� ���� �Է� : ";
	cin >> input;

	if (input < 1 || input > 10)
		throw input;
}

void exceptTest2()
{
	char ch;
	cout << "�޴� : [A]dd\t[D]elete\t[E]xit\n" << endl;
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
		cout << "Err : " << input << "�� ������ ��� �����Դϴ�" << endl;
	}
	catch (char ch)
	{
		cout << "Err : " << ch << "�� �� �� ���� �޴��Դϴ�" << endl;
	}
	catch (...)
	{
		cout << "Err : �Ϻη� ������" << endl;
	}

	return 0;
}