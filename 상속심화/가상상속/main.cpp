#include <iostream>

using namespace std;

class GrandParents
{
public:
	GrandParents()
	{
		cout << "���θ� ������" << endl;
	}
};

class Parents1 : virtual public GrandParents // ������ �ν��Ͻ��� �����Կ� �־ �ֻ��� Ŭ������ �ν��Ͻ��� �ߺ�����Ǵ°� ����
{
public:
	Parents1()
	{
		cout << "�θ�1 ������" << endl;
	}
};

class Parents2 : virtual public GrandParents // ���� �ϳ��� virtual�� ���������� ������ �ȵ�
{
public: 
	Parents2()
	{
		cout << "�θ�2 ������" << endl;
	}
};

class Child : public Parents1, public Parents2
{
public:
	Child()
	{
		cout << "�ڽ� ������" << endl;
	}
};

int main()
{
	Child ch;
	return 0;
}