#include <iostream>

using namespace std;

class Test
// Ŭ������ ����Լ��� ������� ��üó�� �����Ͽ���.
{
public:
	Test() = default;
	~Test() = default;

	int operator() (int a, int b) // �Լ�ȣ�� ������ �� �����Ͽ���
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
	// �ν��Ͻ��� �޾Ƽ� �����ϴµ�, �Լ��� ȣ���Ѱ�ó�� ���δ�!
}

int main()
{
	Test test;
	cout << test() << endl;
	cout << test(3, 4) << endl;

	::test_forTest(test);
}