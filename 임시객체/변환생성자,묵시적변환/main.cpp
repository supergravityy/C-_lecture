#include <iostream>

using namespace std;

class TestData
{
public:
	explicit TestData(const int data) : nData(data) // 변환생성자 -> explicit 묵시적인 변환을 차단
	{
		cout << "TestData(int)" << endl;
	}

	TestData(const TestData& temp) : nData(temp.nData)
	{
		cout << "TestData(const TestData&)" << endl;
	}

	operator int(void) // 묵시적 형변환함수에는 반환형 지정 불가능
	// 이제 필요한 곳에서 인스턴스 자체를 넘겨도 컴파일러가 자동으로 다 해줌
	{
		return this->nData;
	}

	int getData() const
	{
		return this->nData;
	}

	void setData(const int data)
	{
		this->nData = data;
	}

private:
	int nData = 0;
};

void testFunc(const TestData &tempInst) // 메인에서의 이름없는 임시객체는 이제 tempInst라는 이름을 가짐
{
	cout << "testFunc() : " << tempInst.getData() << endl;
}

void print_Add(int B, int A)
{
	cout << "덧셈결과는 : " << B + A << endl;
}

int main()
{
	testFunc(TestData(10)); // == testFunc(10); explicit 차단자로 해당 생성자에 대해 이제 묵시적인 변환을 차단함
	print_Add(TestData(25), 40); // 묵시적형변환

	cout << "메인함수 종료" << endl;
	return 0;
}