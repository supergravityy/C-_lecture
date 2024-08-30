#include <iostream>

using namespace std;

template<typename T>
class MyVector
{
public:
	explicit MyVector(int size) : mSize(size)
	{
		this->mPtr = new T[this->mSize];
		// �̷������� ���ø� Ŭ������ �迭ȭ �Ѵٸ� ���ÿ����÷θ� ���Ҽ� �ִ�.
	}

	~MyVector()
	{
		delete[] this->mPtr;
	}

	// ���� ������ (��������)
	MyVector(const MyVector& source)
	{
		this->mPtr = new T[source.mSize];
		memcpy(this->mPtr, source.mPtr, sizeof(T) * source.mSize);
		mSize = source.mSize;
	}

	// �̵� ������(�̵�����ƽ -> �ӽð�ü ���ϱ�)
	MyVector(MyVector&& source)
	{
		this->operator=(source);
	}

	// ���� ������
	MyVector& operator=(const MyVector& source)
	{
		if (this == &source)
			return *this;

		if (this->mPtr != nullptr)
		{ 
			// �������� ����
			delete[] this->mPtr;
			this->mPtr = new T[source.mSize];
			memcpy(this->mPtr, source.mPtr, sizeof(T) * source.mSize);
			this->mSize = source.mSize;

			return *this;
		}
	}

	// �̵� ���� ������ (���Կ����ڸ� �̵�����ƽ���ε� ���) (��������)
	MyVector& operator=(const MyVector&& source)
	{
		this->mPtr = source.mPtr;
		this->mSize = source.mSize;
		source.mPtr = nullptr;
		source.mSize = 0;
	}

	// �迭������
	T& operator[](int idx)
	{
		if (idx < 0 || idx >= this->mSize)
		{
			cout << "ERROR: �迭�� ��踦 ��� �����Դϴ�." << endl;
			exit(1);
		}

		return this->mPtr[idx];
	}

	// ���ȭ�� �迭������
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