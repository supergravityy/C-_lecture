#include<iostream>

using namespace std;

class Test1
{
public:
	Test1()
	{
		// 스탠다드한 함수선언방식
		data1 = 10;
		data2 = 20;
		cout << "Test1 생성됨" << endl;
	}

	int data1, data2;

	void printData()
	{
		cout << data1 << data2 << endl;
	}

	~Test1()
	{
		cout << "Test1 삭제됨" << endl;
	}
};

class Test2
{
public:
	Test2() : data1(10), data2(20)
	{
		data1 = 20;
		data2 = 30;
		cout << "Test2 생성됨" << endl;
		// C++의 또다른 생성자 선언방법 -> 헷갈리지 말자
		// C++에서 괄호안이 마지막에 실행됨.
	}

	int data1, data2 = 30;

	void printData()
	{
		cout << data1 << data2 << endl;
	}

	~Test2()
	{
		cout << "Test2 삭제됨" << endl;
	}
};

class Test3
{
public:
	// 생성자는 다중으로 정의가 가능하다

	Test3() = default; 
	// default 생성자는 아무것도 안함 -> 일부러 선언,정의들을 안하는 것도 가능

	Test3(int& param) : member(param)
	// 외부변수에 접근할 수 있게하는 참조자를 만드는 생성자
	
	// ☆ 인스턴스를 선언하자마자 클래스의 참조자가 선언 및 초기화가 진행되어야 하기에, 이러한 문법으로밖에 선언이 안된다.
	// 그렇기에, 외부변수에 접근하려면 참조자 대신에 포인터가 더 적절하다
	{} 

	int& member; // int 형 참조자로 선언 -> 외부변수에 접근가능

	void changing()
	{
		member = 50;
	}

	~Test3()
	{}
};

int main()
{
	cout << "메인함수 실행됨" << endl;
	Test1* test1 = new Test1();
	Test2 test2;

	test1->printData(); // 포인터로 선언했기에 구조체와 똑같은 접근방식을 보임
	test2.printData();

	int data = 5;
	cout << "바꾸기전의 지역변수 data : " << data << endl;
	
	Test3 test3(data); // 이제 data 변수는 클래스 멤버와 연결됨
	test3.changing();
	cout << "바꾼후의 지역변수 data : " << data << endl;


	delete test1;

	cout << "메인함수 종료됨" << endl;
	// 메인함수가 종료되고 소멸자가 실행됨을 잘 보여준다.
}