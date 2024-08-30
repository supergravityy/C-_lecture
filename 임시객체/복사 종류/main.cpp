#include <iostream>

using namespace std;

class TestCopy
{
public:
	TestCopy(int data)
	{
		this->Data = new int;
		*(this->Data) = data;
		cout << "original instance" << endl;
	}
	TestCopy(TestCopy& temp) // 깊은 복사가 이루어짐
	{
		this->Data = new int;
		*(this->Data) = *(temp.Data);
		cout << "deep copy" << endl;
	}

	void print()
	{
		cout << "Data : " << *(this->Data) << ", Addr : " << this->Data << endl;
	}

	~TestCopy()
	{
		delete this->Data;
	}
private:
	int* Data = nullptr;
};

int main()
{
	{ 
		// 소멸자의 범위를 지정하기 위해
		TestCopy B(0);
		B.print();
		{
			TestCopy A(20);
			TestCopy C(B);
			A.print(); 
			C.print(); // C와 B는 서로 전혀 다른 값을 가짐

			B = A; // 자료형이 똑같을 때, 안의 멤버값들이 전부 복사됨 -> 얕은 복사
			B.print(); // A의 data멤버가 가리키는 주소를 갖게됨
		}
	}// 해당부분에서 B의 소멸자가 실행되고 오류를 일으킴.
	
}