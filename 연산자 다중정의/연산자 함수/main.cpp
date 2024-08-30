#include <iostream>

using namespace std;

class Mydata
{
public:
	Mydata(int para) : m_Data(para)
	{
		cout << "MyData(int)" << endl;
	}

	Mydata(const Mydata& Inst) : m_Data(Inst.m_Data)
	{
		cout << "MyData(const Mydata&)" << endl;
	}

	Mydata operator + (const Mydata& Inst) const
		// 현재 인스턴스의 내용이 바뀌지 않기에 함수 상수화
	{
		cout << "operator +" << endl;
		Mydata retval(0); // 결과를 저장해야 하기에 임시객체 생성
		retval.m_Data = this->m_Data + Inst.m_Data;
		return retval;
	}

	Mydata& operator = (const Mydata& Inst)
	{
		cout << "operator = " << endl;
		this->m_Data = Inst.m_Data;
		return *this;
	}
	// 왜 반환값과 반환형이 이렇게 고정되어야 하나?
	// a = b = c = d; 같은 코드는 a = ( b = ( c = d )); 의 순서로 작동함. 

	int getData()
	{
		return this->m_Data;
	}

private:
	int m_Data = 0;
};

Mydata operator + (int left, Mydata& Inst)
{
	cout << "global_operator +" << endl;
	Mydata data(left + Inst.getData());

	return data;
}
/*------------------------------------------
* 왜 이 함수를 또 전역으로 선언해주는가?
* 
* 클래스 멤버로 연산자 함수를 선언하려면 맨 왼쪽의 파라미터는 반드시 해당클래스의 인스턴스여야 한다.
* 
* 그러나 사용자 쪽에서는 test1 = test2 + test3; 뿐만 아닌 test1 = 3 + test2; 형식으로도 사용가능하기에
* 연산자함수 멤버 형식에 위배된다. 그래서 전역으로 선언해준다.
* 혹시 test1 = 3 + test2; 형식으로 선언할 수 있기에, 반대로도 선언해주어야 한다
* 
* 만약, 이 순서를 지키지 않는다면 -> test1 = test2 + 3;
* 3을 임시객체로 선언하고, + 연산자 멤버함수의 형태로 컴파일러가 바꿔버린다. -> 의도치 않은 임시객체 또 생성
* 왜냐하면, class + class 형식의 연산과 int + class 형식의 연산만 정의 되어 버리기에 컴파일러가 1번째 형식의 연산으로 지맘대로 바꿔버리기 때문
------------------------------------------*/

int main()
{
	cout << "*** begin ***" << endl;

	Mydata test1(0), test2(1), test3(2);

	test1 = test2 + test3; // test1.operator=( test2.operator+(test3) )
	// 위의 형태로 작성하는게 편의성이 뛰어남
	cout << test1.getData() << endl;

	test1 = 3 + test2;
	cout << test1.getData() << endl;

	cout << "*** end ***" << endl;
	return 0;
}