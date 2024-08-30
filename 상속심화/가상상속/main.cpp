#include <iostream>

using namespace std;

class GrandParents
{
public:
	GrandParents()
	{
		cout << "조부모 생성자" << endl;
	}
};

class Parents1 : virtual public GrandParents // 최하위 인스턴스를 선언함에 있어서 최상위 클래스의 인스턴스가 중복선언되는걸 방지
{
public:
	Parents1()
	{
		cout << "부모1 생성자" << endl;
	}
};

class Parents2 : virtual public GrandParents // 만약 하나라도 virtual을 선언해주지 않으면 안됨
{
public: 
	Parents2()
	{
		cout << "부모2 생성자" << endl;
	}
};

class Child : public Parents1, public Parents2
{
public:
	Child()
	{
		cout << "자식 생성자" << endl;
	}
};

int main()
{
	Child ch;
	return 0;
}