#include <iostream>

int testFunc(int param)
{
	int result = param * 2;
	return result;
}

int main()
{
	int input = 0;

	std::cout << "숫자입력 : ";
	std::cin >> input;

	int&& r_val = (input + 5); 
	// 연산과정에서 임시객체가 생성됨 (이름 X) -> 대입연산후 임시객체는 소멸된다.
	// 그러나 &&로 임시객체에 이름을 부여하고 소멸과정을 없애면 지역변수로 되살려서 사용가능하다
	std::cout << r_val << std::endl;

	int&& result = testFunc(10); // 반환값도 임시객체로 완성됨
	result += 10;
	// 소멸되어야 하는 임시객체를 되살려서 사용하고 있다.
	std::cout << result << std::endl;

	return 0;
}