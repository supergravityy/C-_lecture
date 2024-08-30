#include <iostream>

using namespace std;

template<typename T>
class MyVector
{
public:
	explicit MyVector(int size) : mSize(size)
	{
		this->mPtr = new T[this->mSize];
		// 이런식으로 템플릿 클래스를 배열화 한다면 스택오버플로를 피할수 있다.
	}

	~MyVector()
	{
		delete[] this->mPtr;
	}

	// 복사 생성자 (깊은복사)
	MyVector(const MyVector& source)
	{
		this->mPtr = new T[source.mSize];
		memcpy(this->mPtr, source.mPtr, sizeof(T) * source.mSize);
		mSize = source.mSize;
	}

	// 이동 생성자(이동세멘틱 -> 임시객체 취하기)
	MyVector(MyVector&& source)
	{
		this->operator=(source);
	}

	// 대입 연산자
	MyVector& operator=(const MyVector& source)
	{
		if (this == &source)
			return *this;

		if (this->mPtr != nullptr)
		{ 
			// 깊은복사 수행
			delete[] this->mPtr;
			this->mPtr = new T[source.mSize];
			memcpy(this->mPtr, source.mPtr, sizeof(T) * source.mSize);
			this->mSize = source.mSize;

			return *this;
		}
	}

	// 이동 대입 연산자 (대입연산자를 이동세멘틱으로도 사용) (얕은복사)
	MyVector& operator=(const MyVector&& source)
	{
		this->mPtr = source.mPtr;
		this->mSize = source.mSize;
		source.mPtr = nullptr;
		source.mSize = 0;
	}

	// 배열연산자
	T& operator[](int idx)
	{
		if (idx < 0 || idx >= this->mSize)
		{
			cout << "ERROR: 배열의 경계를 벗어난 접근입니다." << endl;
			exit(1);
		}

		return this->mPtr[idx];
	}

	// 상수화된 배열연산자
	T& operator[](int idx) const
	{
		return this->operator[](idx);
	}

	int getSize() { return this->mSize; }

private:
	int mSize;
	T* mPtr;
};

int main()
{
	MyVector<int> arr(15);

	for (int idx = 0; idx < 15; idx++)
		arr[idx] = idx;

	for (int idx = 0; idx < 15; idx++)
		cout << arr[idx] << "\t" ;
	cout << endl;

	MyVector<int> arr2(3);
	arr2 = arr;

	for (int idx = 0; idx < 5; idx++)
		cout << arr2[idx] << "\t";
	cout << endl;

	return 0;
}