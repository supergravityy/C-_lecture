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

	int operator[](const int idx) const // ��ȯ���� int�̱⿡ read -> rVal
	{
		cout << "operator[] const" << endl;
		return pBuff[idx];
	}

	int& operator[](const int idx) // ��ȯ���� �������̱⿡ write -> lVal
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
	cout << tempArr[3] << endl; // read �̱⿡ ��ȯ���� �������� ���;� �Ѵ�
}

int main()
{
	IntArr arr(5); // �����ڰ� �׸�ŭ�� �迭�� �������

	for (int i = 0; i < 5; ++i)
		arr[i] = i * 10; // write�̱⿡, ��ȯ���� �������� ���;� �Ѵ�

	testFunc(arr);
	return 0;
}