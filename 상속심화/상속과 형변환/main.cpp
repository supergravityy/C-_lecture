#include <iostream>

using namespace std;

class MyData
{
public:
	MyData() {}
	virtual ~MyData() {}

	void setData(int para) 
	{ 
		cout << "부모 setter" << endl;
		this->m_Data = para;
	}
	int getData() 
	{
		cout << "부모 getter" << endl;
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
		cout << "자식 setter" << endl;
		if (para > 10) para = 10;
		else if (para < 0) para = 0;

		MyData::setData(para);
	}

	void printData()
	{
		cout << "자식 getter" << endl;
		cout << "출력 : " << this->getData() << endl;
	}
};

int main()
{
	MyData* p_Data = new MyDataEx; // 추상자료형으로 포인팅
	MyDataEx* p_newData = nullptr;

	p_Data->setData(15); // 그냥 대입만 함
	cout << p_Data->getData() << endl;

	p_newData = static_cast<MyDataEx*>(p_Data); // 정적캐스팅
	// 원래는 p_Data는 메모리상 부모클래스까지만 포인팅하지만, 정적캐스팅을 함으로써, 자식클래스 부분까지 전부 포인팅
	// 이제 대상을 두 포인터변수가 가리키지만 가리키는 범위가 다르다.

	p_newData->setData(20);
	p_newData->printData();

	delete p_Data;
	return 0;
}