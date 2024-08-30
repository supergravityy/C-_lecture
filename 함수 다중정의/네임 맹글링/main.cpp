#include <iostream>

using namespace std;

/*
void testFunc();

 이 함수의 진짜 이름, 컴파일러가 지은 진짜 이름은
?testFunc@@YAXXZ 이다. 

//{
//	cout << "::testFunc()" << endl;
//}
// 링크오류를 일부로 일으키면 어떻게 컴파일러가 이름을 바꿨는지 알 수 있다.
*/

// 그러나 일부러 네임 맹글링을 막을 수도 있다.
// extern "C" 키워드를 쓰면 C함수처럼 맹글링을 안하고 함수의 이름이 진짜 이름이다.

extern "C" void testFunc()
{
	cout << "::testFunc()" << endl;
}


namespace Test
{
	void testFunc()
	{
		cout << "Test::testFunc()" << endl;
	}
}

namespace MyData
{
	void testFunc()
	{
		cout << "MyData::TestFunc()" << endl;
	}
}

int main()
{
	testFunc();
	::testFunc();
	Test::testFunc();
	MyData::testFunc();

	return 0;
}