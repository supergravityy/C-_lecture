#include <iostream>

using namespace std;

class MyData
{
public:
	MyData()
	{
		cout << "생성자" << endl;
	}

	~MyData()
	{
		cout << "소멸자" << endl;
	}

	void methodTest()
	{
		cout << "메서드~~" << endl;
	}
};

int main()
{
	unique_ptr<MyData> ptrTest1(new MyData); // shared 포인터처럼 동시참조 지원 안함, 그외엔 똑같다
	unique_ptr<MyData> ptrTest2;

	/*---------------------------------*/
	// 오류상황 
	// ptrTest2 = ptrTest1;
	// unique_ptr<MyData> ptrTest3(ptrTest1);
	//
	// 근데 오류가 이런 상황이란걸 당최 알아먹을수 없게 나온다.....
	/*---------------------------------*/
}