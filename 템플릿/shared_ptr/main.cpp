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

void removeArr(MyData* ptrInst)
{
	cout << "동적으로 할당한 배열 삭제~" << endl;

	delete[] ptrInst;
}

int main()
{
	{
		cout << "이동세멘틱 문제 해결 ! 시작----------------------------" << endl;
		shared_ptr<MyData> ptrTest1(new MyData);

		cout << "(원본) 포인팅 카운터값 : " << ptrTest1.use_count() << endl;
		cout << "(원본) 포인팅 주소값 : " << ptrTest1.get() << endl;

		shared_ptr<MyData> ptrTest2;
		ptrTest2 = ptrTest1;	// 이동세멘틱 현상 사라짐

		cout << "(원본) 포인팅 카운터값 : " << ptrTest1.use_count() << endl;
		cout << "(원본) 포인팅 주소값 : " << ptrTest1.get() << endl;

		shared_ptr<MyData>ptrTest3(ptrTest2); // 얕은복사 생성자? (이동세멘틱X)
		cout << "(원본) 포인팅 카운터값 : " << ptrTest1.use_count() << endl;
		cout << "(원본) 포인팅 주소값 : " << ptrTest1.get() << endl;

		ptrTest1->methodTest();
		ptrTest2->methodTest();
		ptrTest3->methodTest(); // 대상 메서드 사용가능
	}
	cout << "이동세멘틱 문제 해결 ! 종료----------------------------" << endl << endl;

	{
		cout << "동적배열할당 문제 해결 ! 시작 ----------------------------" << endl;

		shared_ptr<MyData>ptrTest4(new MyData[4], removeArr); // qsort 처럼 콜백구조로 배열전체를 깔끔히 제거가능
	}
	cout << "동적배열할당 문제 해결 ! 종료 ----------------------------" << endl;
}