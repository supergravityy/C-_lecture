#include <iostream>

int main()
{
	int data(10);

	int& ref = data; // 참조자는 선언과 동시에 초기화가 될것
	ref = 20;
	std::cout << ref << std::endl; // 메모리 구조를 보면, 포인터와 똑같은 매커니즘으로 작동한다

	int* pnt = &data;
	*pnt = 30;
	std::cout << *pnt << std::endl;

	std::cout << "주소출력" << std::endl;
	std::cout << "&data : " << &data << std::endl;
	std::cout << "&ref : " << &ref << std::endl; // 참조자에 &를 붙여서 출력시, 참조대상의 주소값을 가리킴 
	std::cout << "&pnt : " << &pnt << std::endl;

	return 0;
}