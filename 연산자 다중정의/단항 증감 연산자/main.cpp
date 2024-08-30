#include <iostream>

using namespace std;

class operTest
{
public:
	operTest(int num)
	{
		this->Data = num;
	}
	~operTest() = default;

	int operator++()
	{
		cout << "전위 연산자 : ++num" << endl;
		return ++(this->Data);
	}

	int operator++(int)
	{
		cout << "후위 연산자 : num++" << endl;
		int temp = (this->Data)++; // 후위 연산자는 연산 이전의 값을 반환한다는 것을 주의하자

		return temp;
	}

	/*----------------------------------------
	* operTest& operator(int)
	* {
	*		int data  = this->Data++ ;
	*		return *this;
	* }
	* 
	* 추천되지 않지만, 이런식으로도 활용이 가능
	* 
	* 사용처에선 cout << NUM++++++++ << endl; 이런식으로도 코딩가능 -> 비추천
	------------------------------------------*/

	operator int()
	{
		return this->Data;
	}

private:
	int Data = 0;
};

int main()
{
	operTest test(20);

	cout << ++test << endl;
	cout << test++ << endl;
	cout << test << endl; // 함수호출 연산자 -> test()와 똑같다

	return 0;
}