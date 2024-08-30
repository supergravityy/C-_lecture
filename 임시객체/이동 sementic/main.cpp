#include <iostream>

using namespace std;

class TestData
{
public:
	TestData()
	{
		cout << "TestData()" << endl;
		this->nData = new int(0);
	}

	TestData(const TestData& temp) // deepcopy
	{
		cout << "TestData(const TestData&)" << endl;
		this->setData(temp.getData());
	}

	TestData(TestData&& Rval) noexcept // shallowcopy (이동생성자)

	// noexcept -> 예외처리가 발생되지 않음 [습관적으로 무조건 써주자]
	{
		cout << "TestData(TestData&&) - move" << endl;
		delete this->nData;				// 현 포인터멤버가 뭘 가리키던 일단 해제 (메모리 누수 방지)
		this->nData = Rval.nData;		// 임시객체의 포인팅 주소를 가져와라
		Rval.nData = nullptr;			// 임시객체 포인터멤버는 널처리 -> free나 delete나 NULL을 받게되면 실행안됨 (해당영역 보존)
	}

	~TestData() noexcept // 생성/소멸 과정은 실패하면 안됨 -> 예외처리도 없을것
	{
		cout << "~TestData()" << endl;
		delete this->nData;
	}

	void operator = (TestData& temp)
	// 원래는 밑에 처럼 대입연산자를 다시 선언시, 반환형은 현재인스턴스에 대한 참조를 반환하게 해야함
	{
		cout << "operator=(TestData&)" << endl;
		setData(temp.getData());
	}

	TestData& operator = (TestData&& Rval) noexcept // shallowcopy (이동 대입 연산자)
	// 이동생성자 와 이동대입연산자는 따라다님!!! -> 새로선언해서 받을거나, 기존것으로 받을거냐 이 차이이다.
	{
		cout << "operator=(TestData&&) - move" << endl;
		delete this->nData;
		this->nData = Rval.nData;
		Rval.nData = nullptr;

		return *this; // 본인을 참조자로 반환함 (L값) -> C++에선 연쇄대입이 가능하기에
	}

	/*
	* 예를 들어서, 
	TestData A,B,C ;
	A = B = C = getTestData(53); 
	이런형태의 연쇄대입을 지원하기위해 위와 같은 반환형은 필요하다.
	*/

	/*
	* TestData& operator=(TestData&& rhs) noexcept {
		cout << "operator=(TestData&&) - move" << endl;
		delete pnData;
		pnData = rhs.pnData;
		rhs.pnData = nullptr;
		return *this;
	}
	현재는 이렇게 써도됨.
	*/

	int getData() const
	{
		return *nData;
	}

	void setData(int data)
	{
		if (nData != nullptr)
			delete nData;
		nData = new int;
		*nData = data;
	}

private:
	int* nData = nullptr;
};

TestData getTestData(int para)
{
	cout << "getTestData()" << endl;
	TestData test;

	test.setData(para);
	return test;
}

int main()
{
	cout << "*** Before ***" << endl;

	TestData t1 = getTestData(5); // 이러한 코드는 컴파일러가 최적화 시켜서 임시객체의 생성/소멸을 볼 수 없음

	TestData t2(std::move(getTestData(10))); // std::move 함수를 쓰면 최적화를 억제시켜 볼 수 있다.

	TestData t3(t2); // 복사생성자로 t2의 내용을 딥카피했다

	TestData result;
	result = getTestData(15); // 임시객체 Rval 값을 대입연산자를 재정의하여 안의 내용을 이동시킴 (43번줄의 코드)

	cout << "*** after ***" << endl;
	return 0;
}