#include <iostream>

using namespace std;

template<typename T>
class Test
{
public:
	Test();
	T TestFunc();

protected:
	static T mData;
};

// �ܺο� �޼��� ����
template<typename T> // �׻� ���ø��� ���ֱ�
Test<T>::Test()
{
	cout << "Test Ŭ���� ������" << endl;
}
template<typename T>
T Test<T>::TestFunc()
{
	return this->mData;
}

// �ܺο� ������� ����
template<typename T>
T Test<T>::mData = 15;

int main()
{
	Test<double> test;
	cout << test.TestFunc() << endl;

	return 0;
}