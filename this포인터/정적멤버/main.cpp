#include <iostream>

using namespace std;

class Test
{
public:
	Test(int data)
	{
		this->nData = data;
		instCount++;
	}

	int getData()
	{
		return nData;
	}

	void resetCount()
	{
		instCount = 0;
	}

	static int getCount()
	{
		return instCount;
	}

private:
	int nData = 0;
	
	static int instCount;

	//static int instCount = 0; �̷������� �ʱ�ȭ�� �ȵǴ� ����
	// ��������� Ŭ������ ��� �ν��Ͻ����� �����Ǳ⿡ Ŭ���� ���ο��� �����ʱ�ȭ�Ǹ� �ȵȴ�!!!!!
};

int Test::instCount = 0; // �׷��� �ܺο��� �ʱ�ȭ�� ����� �Ѵ�.

int main()
{
	Test a(5), b(10);

	cout << a.getCount() << endl;
	b.resetCount();

	cout << Test::getCount() << endl;

	return 0;
}