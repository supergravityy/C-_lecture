#include <iostream>

using namespace std;

class MyData
{
public:
	MyData()
	{
		cout << "MyData()" << endl;
	}

	MyData(const MyData& temp) : nData(temp.nData) // 복사생성자
	// 원본 인스턴스를 참조자로 받아서 그 안의 멤버변수를 현재 인스턴스 멤버로 복사
	{
		cout << "MyData(const MyData&)" << endl;
	}

	int getData()
	{
		return nData;
	}

	void setData(const int data)
	{
		nData = data;
	}

private:
	int nData = 0;
};

int main()
{
	MyData a;
	a.setData(10);

	MyData b(a);
	cout << b.getData() << endl;

	return 0;
}