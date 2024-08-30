#include <iostream>

using namespace std;

class MyInterface // 순수가상클래스 = 인터페이스 클래스 -> 인스턴스 선언 자체가 안됨
{
public:
	MyInterface()
	{
		cout << "MyInterface()" << endl;
	}

	virtual int getData() const = 0; // 순수가상 메서드 정의
	virtual void setData(int para) = 0;
};

class MyData : public MyInterface
{
public:
	MyData()
	{
		cout << "MyData()" << endl;
	}

	virtual int getData() const
	{
		return this->m_Data;
	}
	virtual void setData(int para)
	{
		this->m_Data = para;
	}
private:
	int m_Data = 0;
};

int main()
{
	//MyInterface Inst; //인스턴스 선언 불가능
	MyData Inst;
	Inst.setData(25);
	cout << Inst.getData() << endl;

	return 0;
}