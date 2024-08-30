#include <iostream>

using namespace std;

void testFunc(int& val)
{
	cout << "testFunc(int&)" << endl;
}

void testFunc(int&& val) // r값 참조 : 
{
	cout << "testFunc(int&&)" << endl;
}

//void testFunc(int val)
//{
//	cout << "testFunc(int)" << endl;
//}

// 해당 함수의 주석을 풀면, 오류가 발생 -> 함수 다중정의여도 컴파일러가 콜러의 조건에 상응하는 함수를 자동으로 꽂아주지만,
// 이와같은 함수는 복사를 해오기에, r값 l값 참조함수 두개를 대체할 수도 있기에 오류를 발생시킴 
// 컴파일러 : 그래서 뭘 선택할건데....

int main()
{
	testFunc(3 + 4);
	testFunc(12);

	int A = 10;
	testFunc(A);

	return 0;
}