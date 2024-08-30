#include <iostream>

using namespace std;

template<typename T>
class Test
{
public:
	Test() = default;
	virtual ~Test() = default;

protected:
	T mData;
};

template<typename T>
class TestEx : public Test<T>
{
public:
	TestEx() = default;
	virtual ~TestEx() = default;

	T getData() const { return this->mData; }
	void setData(T para) { this->mData = para; }
	/*********************
	* 
	* C++ 템플릿 클래스에서는 이름숨김 문제때문에 this포인터를 명시적으로 사용해야함
	* 특히 부모클래스가 템플릿 클래스인 경우, 컴파일러는 그 멤버변수가 자식클래스에 속한건지 확신못함
	* 명시적으로 this포인터를 사용하여, 부모클래스의 멤버라는것을 컴파일러에게 알려줘야 함.
	* 
	**********************/
};

int main()
{
	TestEx<int> test;
	test.setData(15);

	cout << test.getData() << endl;

	return 0;
}