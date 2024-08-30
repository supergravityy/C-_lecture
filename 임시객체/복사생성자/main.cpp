#include <iostream>

using namespace std;

class MyData
{
public:
	MyData()
	{
		cout << "MyData()" << endl;
	}

	MyData(const MyData& temp) : nData(temp.nData) // ���������
	// ���� �ν��Ͻ��� �����ڷ� �޾Ƽ� �� ���� ��������� ���� �ν��Ͻ� ����� ����
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