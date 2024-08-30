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
};

void testFunc()
{
	cout << "*****testFunc 시작*****" << endl;
	auto_ptr<MyData> ptrTest1(new MyData);
	cout << "*****testFunc 종료*****" << endl;

	// 사용법 : auto_ptr <참조할 영역> 인스턴스이름(동적할당 구문);
}

int main()
{
	testFunc();

	cout << "*****문제점1 시작*****" << endl;
	{
		auto_ptr<MyData> ptrTest2(new MyData);
		auto_ptr<MyData> ptrTest3;

		// 문제점 1. 여기서 대입연산자는 이동세멘틱 같은 역할 -> 많이 헷갈림
		cout << "ptrTest2 포인팅주소 : 0x" << ptrTest2.get() << endl;
		ptrTest3 = ptrTest2;
		// 혹시라도 ptrTest2로 MyData 메서드를 사용시 바로 Heap 오류 발생!
		cout << "ptrTest2 포인팅주소 : 0x" << ptrTest2.get() << endl;
	}
	cout << "*****문제점1 종료*****" << endl;

	cout << "*****문제점2 시작*****" << endl;
	{
		// 문제점 2. 배열로 선언시, 소멸할때, 하나만 지움 -> 현재 여기서 나머지 2개는 계속 존재 -> 메모리 누수
		auto_ptr<MyData> ptrTest4(new MyData[3]);
		// 이는 auto_ptr의 소멸자가 delete[] 를 하지 않기 때문!!!!!
	}
	cout << "*****문제점2 종료*****" << endl;
}
