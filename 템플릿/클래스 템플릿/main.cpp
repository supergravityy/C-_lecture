#include <iostream>

using namespace std;

template<typename T>

class MyData
{
public:
	MyData(T para) : m_data(para){}

	T getData() const { return this->m_data; }

	operator T() { return this->m_data; }
	void setData(T para) { this->m_data = para; }

private:
	T m_data;
}; // 이 클래스로 인스턴스가 생성되지 않으면, 이 클래스는 컴파일 타임에 생략된다.

class Test
{
public:
	Test(int n)
	{
		cout << "Test 생성자" << endl;
	}
};

int main()
{
	MyData<int> a(5);
	cout << a << endl;
	MyData<double> b(3.141592);
	cout << b << endl;

	MyData<Test> c(25); // 이런식으로도 선언이 가능 -> vector<string> 을 생각하자

	return 0;
}