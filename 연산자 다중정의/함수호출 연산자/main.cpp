#include <iostream>

using namespace std;

class Test
// 클래스를 기능함수를 묶어놓은 객체처럼 정의하였다.
{
public:
	Test() = default;
	~Test() = default;

	int operator() (int a, int b) // 함수호출 연산자 를 정의하였다
	{
		return a + b;
	}

	int operator() ()
	{
		return 0;
	}
};

void test_forTest(Test& para) 
{
	cout << para(5, 10) << endl;
	// 인스턴스를 받아서 실행하는데, 함수를 호출한것처럼 보인다!
}

int main()
{
	Test test;
	cout << test() << endl;
	cout << test(3, 4) << endl;

	::test_forTest(test);
}