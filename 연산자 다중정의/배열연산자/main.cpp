#include <iostream>

using namespace std;

class IntArr
{
public:
	IntArr(const int size)
	{
		this->pBuff = new int[size] {0};
		this->size = size;
	}

	~IntArr()
	{
		delete pBuff;
		pBuff = nullptr;
	}

	int operator[](const int idx) const // 반환값이 int이기에 read -> rVal
	{
		cout << "operator[] const" << endl;
		return pBuff[idx];
	}

	int& operator[](const int idx) // 반환값이 참조형이기에 write -> lVal
	{
		cout << "operator[]" << endl;
		return pBuff[idx];
	}

private:
	int* pBuff = nullptr;
	int size = 0;
};

void testFunc(const IntArr& tempArr)
{
	cout << "testFunc()" << endl;
	cout << tempArr[3] << endl; // read 이기에 반환값은 정수형이 들어와야 한다
}

int main()
{
	IntArr arr(5); // 생성자가 그만큼의 배열을 만들어줌

	for (int i = 0; i < 5; ++i)
		arr[i] = i * 10; // write이기에, 반환값은 참조형이 들어와야 한다

	testFunc(arr);
	return 0;
}