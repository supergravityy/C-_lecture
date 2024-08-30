#include <iostream>

using namespace std;

class MyData
{
public :
	MyData()
	{}
	~MyData()
	{}
	void setData(int para)
	{
		this->m_Data = para;
	}
	int getData()
	{
		return this->m_Data;
	}

private:
	int m_Data = 0;
};

class MyDataEx : public MyData
{
public:
	void setData(int para) 
	{
		if (para < 0)
			MyData::setData(0);
		else if (para > 10)
			MyData::setData(10);
		else
			MyData::setData(para);
	}

	// 부모의 Data 멤버변수가 프라이빗이기에 자식도 접근 못함
	// 그래서 -> "부모네임스페이스"::"부모메서드"()
	// 를 사용해서, 오버라이드 전의 메서드도 사용이 가능하다.
};

int main()
{
	MyData test1;

	test1.setData(20);

	MyDataEx test2;
	test2.setData(15);

	cout << "test1(parents) : " << test1.getData() << endl;
	cout << "test2(child) : " << test2.getData() << endl;
	
}