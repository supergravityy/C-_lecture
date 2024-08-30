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
}; // �� Ŭ������ �ν��Ͻ��� �������� ������, �� Ŭ������ ������ Ÿ�ӿ� �����ȴ�.

class Test
{
public:
	Test(int n)
	{
		cout << "Test ������" << endl;
	}
};

int main()
{
	MyData<int> a(5);
	cout << a << endl;
	MyData<double> b(3.141592);
	cout << b << endl;

	MyData<Test> c(25); // �̷������ε� ������ ���� -> vector<string> �� ��������

	return 0;
}