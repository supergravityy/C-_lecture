#include <iostream>
#include <new>

using namespace std;

// 사전작업 : x64가 아닌 x86으로 시도 (사용가능한 메모리때문)

// 에러상황 1. size에 음수입력
// 에러상황 2. size값을 1.7G 이상 작성해보기

class Test
{
public:
	Test(int size) // 여기서 size가 음수일때는 언더플로가 발생 -> unsigned로 바뀌면 어마어마한 수가 됨
	{
		this->mData = new char[size];
		cout << "할당성공!" << endl;
	}
	~Test()
	{
		delete[] this->mData;
		cout << "해제성공!" << endl;
	}

private:
	char* mData;
};

int main()
{
	try
	{
		int memSize;
		cout << "입력사이즈 : ";
		cin >> memSize;
		
		Test temp(memSize);
	}
	catch (bad_alloc& exp) // bad_alloc 클래스는 std안에 있음.
	{
		cout << exp.what() << endl;
		cout << "Err : Test 인스턴스 생성실패" << endl;
	}

	return 0;
}