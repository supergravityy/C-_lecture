#include <iostream>

using namespace std;

class MyData
{
public:
	MyData()
	{
		cout << "������ȣ��" << endl;
	}

	void setData(int num)
	{
		cout << "setData() ȣ��" << endl;
		this->mData = num;
	}

	int getData()
	{
		cout << "getData() ȣ��" << endl;
		return this->mData;
	}

private:
	int mData = 0;
};

void testFunc(const MyData& refData)
{
	MyData& data = const_cast<MyData&>(refData);
	// const_cast<MyData&>(refData) �� ���ȭ�� �ν��Ͻ��� ���ȭ�� Ǯ�� �ӽð�ü(������)�� ��ȯ
	// �̸� data �����ڰ� ������, ������� ����
	// ���� �����ؼ�, const MyData* refData ����, ����Ű�� �����ͺ����� MyData *refData2�� �ٲٴ°� -> �ν��Ͻ��� �ּҸ� ��ȯ
	// �����ڿ� �����ʹ� ASM �������� �Ϻ��� �Ȱ���

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