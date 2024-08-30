#include <iostream>

using namespace std;

int C_StyleERR()
{
	// C 스타일 에러처리

	int a = 100, b;
	cout << "숫자입력 : ";
	cin >> b;

	if (b == 0)
		goto ERR; // 통상적으로 goto를 이용해왔다

	cout << a / b << endl;
	return 0;

ERR:
	cout << "0으로 나눌수 없음" << endl;
	return -1;
}

int Cpp_StyleERR()
{
	// C++ 스타일 에러처리

	int a = 100, b;
	cout << "숫자입력 : ";
	cin >> b;

	try // 실행하는 부분
	{
		if (b == 0)
			throw b; // 예외시 예외상황을 던짐
		else
			cout << a / b << endl;
	}
	catch (int err_num) // 해당 예외상황을 받아서 그에 맞는 처리
	{
		cout << err_num << "으로 나눌 수 없음" << endl;
	}
	return 0;
}

int main()
{
	C_StyleERR();

	Cpp_StyleERR();
}