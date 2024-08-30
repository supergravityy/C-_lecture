#include <iostream>

using namespace std;

class Parents // Vtable을 직접뜯어보기 위함 -> 조사식의 this포인터의 내용에 __vfptr 라는 배열을 확인하면 됨
{
public:
	Parents()
	{cout << "부모 생성자" << endl;} // 자식 인스턴스가 선언되면서 가장먼저 실행되는 생성자 -> vfptr의 요소들이 부모메서드로 업데이트됨

	virtual ~Parents()
	{cout << "부모 소멸자" << endl;}

	virtual void test1()
	{cout << "부모::테스트1" << endl;}

	virtual void test2()
	{cout << "부모::테스트2" << endl;}
};

class Child : public Parents
{
public:
	Child()
	{cout << "자식 생성자" << endl;} // 그 다음으로 실행되는 생성자 -> vfptr의 요소들의 자식메서드로 업데이트됨

	~Child()
	{cout << "자식 소멸자" << endl;}

	void test1()
	{cout << "자식::테스트1" << endl;}

	void test2()
	{cout << "자식::테스트2" << endl;}
};

int main()
{
	Parents* forTest = new Child;

	return 0; 
}