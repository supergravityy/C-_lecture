#include <iostream>

void testFunc(int a, int b)
{
	std::cout << "매개변수 두개!" << std::endl;
}

void testFunc(int a, int b, int c = 10)
{
	std::cout << "매개변수 두개 + default 1개!" << std::endl;
}

int main()
{
	//testFunc(2, 1); 
	// 이러한 경우에는 컴파일 단계에서 변수 두개,세개 함수를 선택 불가 -> 컴파일 오류 발생

	testFunc(1, 2, 3);

	return 0;
}