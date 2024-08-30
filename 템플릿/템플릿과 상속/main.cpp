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
	* C++ ���ø� Ŭ���������� �̸����� ���������� this�����͸� ��������� ����ؾ���
	* Ư�� �θ�Ŭ������ ���ø� Ŭ������ ���, �����Ϸ��� �� ��������� �ڽ�Ŭ������ ���Ѱ��� Ȯ�Ÿ���
	* ��������� this�����͸� ����Ͽ�, �θ�Ŭ������ �����°��� �����Ϸ����� �˷���� ��.
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