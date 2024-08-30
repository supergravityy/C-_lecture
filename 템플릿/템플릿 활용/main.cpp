#include <iostream>

using namespace std;

template<typename T>
class Test
{
public:
	Test();
	T TestFunc();

protected:
	static T mData;
};

// 외부에 메서드 정의
template<typename T> // 항상 템플릿을 써주기
Test<T>::Test()
{
	cout << "Test 클래스 생성자" << endl;
}
template<typename T>
T Test<T>::TestFunc()
{
	return this->mData;
}

// 외부에 정적멤버 정의
template<typename T>
T Test<T>::mData = 15;

int main()
{
	Test<double> test;
	cout << test.TestFunc() << endl;

	return 0;
}