#include <iostream>

template <typename T>

T add(T a, T b)
{
	return a + b;
	// 함수 템플릿 문법을 사용하여, 컴파일 타임에서 파라미터의 자료형을 
	// 호출자가 의도한 바와 같게 받을 수 있다
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.3, 4.4) << std::endl;
	std::cout << add('b', 'd') - 'a' << std::endl;

	// 컴파일 타임에서 템플릿 문법으로 인해 add 함수가 3번이나 선언된다.
}