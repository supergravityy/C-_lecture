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

	//static int instCount = 0; 이런식으로 초기화가 안되는 이유
	// 정적멤버는 클래스의 모든 인스턴스에서 공유되기에 클래스 내부에서 직접초기화되면 안된다!!!!!
};

int Test::instCount = 0; // 그래서 외부에서 초기화를 해줘야 한다.

int main()
{
	Test a(5), b(10);

	cout << a.getCount() << endl;
	b.resetCount();

	cout << Test::getCount() << endl;

	return 0;
}