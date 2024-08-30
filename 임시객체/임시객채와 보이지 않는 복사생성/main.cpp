#include <iostream>

using namespace std;

class TestData
{
public:
	TestData(const int data) : nData(data) // 변환생성자 (나중에 배울내용)
	{
		cout << "TestData(int)" << endl;
	}

	TestData(const TestData& temp) : nData(temp.nData)
	{
		cout << "TestData(const TestData&)" << endl;
	}

	~TestData()
	{
		cout << "~TestData(" << nData << ")" << endl;
		// 소멸시, 멤버데이터가 뭐였는지 알려줌
	}

	int getData() const
	{
		return nData;
	}

	void setData(const int data)
	{
		this->nData = data;
	}

private:
	int nData = 0;
};

TestData testFunc(TestData tempInst) 
// 효율성을 위한 상수형참조를 파라미터단, 반환단에 둘다 하지 않았다
{
	cout << "testFunc()" << endl;
	tempInst.setData(20);
	return tempInst;
}

TestData testFunc2(TestData& tempInst) // 조금이라도 생성을 덜하기 위해
{
	cout << "testFunc()" << endl;
	tempInst.setData(20);
	return tempInst;
}

int main()
{
	cout << "1번 테스트" << endl;

	testFunc(10).setData(100); // 파라미터로 10을 준것은 TestData temp(10) 과 같다. 
	/*-----
	* 순서
	* 
	* 1. TestData의 임시 인스턴스를 자동선언 -> 생성자 중에 변수 하나를 받으면 멤버변수를 초기화시키는 함수 존재
	* 2. testFunc는 해당 임시 인스턴스를 매개변수로 받음 -> 임시객체 생성됨 
	* 3. testFunc가 반환될 때, 또다시 임시 인스턴스를 매개변수로 받음 -> 임시객체 생성됨 -> 매개변수 임시객체 소멸됨
	* 4. 콜러에서 반환을 안받음 -> 반환 임시객체 의존성 X -> 소멸
	* 
	* 개인적인 생각 : C++은 효율성을 논하는 프로그래밍 언어인데, 객체생성소멸이 내부적으로 일어나게 되는건 비효율의 측면이 아닌가?
	-----*/

	cout << "2번 테스트" << endl;

	TestData result = testFunc(10); // 이제는 이 반환 임시객체를 result가 원본으로 취함
	result.setData(300);

	cout << "3번 테스트" << endl;

	TestData result2 = testFunc2(result); // 이젠 테스트함수의 파라미터는 있던 결과를 참조형으로 받는다 -> 생성자 호출 X
	// 그러나, 1번처럼 그냥 상수로 정의후 파라미터로 넘길시, 임시객체 생성됨
	result.setData(1000);

	cout << "메인함수 종료" << endl;
	return 0;
}