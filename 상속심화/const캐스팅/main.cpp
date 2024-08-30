#include <iostream>

using namespace std;

class MyData
{
public:
	MyData()
	{
		cout << "생성자호출" << endl;
	}

	void setData(int num)
	{
		cout << "setData() 호출" << endl;
		this->mData = num;
	}

	int getData()
	{
		cout << "getData() 호출" << endl;
		return this->mData;
	}

private:
	int mData = 0;
};

void testFunc(const MyData& refData)
{
	MyData& data = const_cast<MyData&>(refData);
	// const_cast<MyData&>(refData) 는 상수화된 인스턴스의 상수화를 풀은 임시객체(참조자)를 반환
	// 이를 data 참조자가 받으면, 멤버변경 가능
	// 쉽게 생각해서, const MyData* refData 에서, 가리키는 포인터변수를 MyData *refData2로 바꾸는것 -> 인스턴스의 주소를 반환
	// 참조자와 포인터는 ASM 시점에서 완벽히 똑같다

	data.setData(10);
}

int main()
{
	MyData data;
	data.setData(5);
	testFunc(data);

	cout << data.getData() << endl;
	return 0;
}