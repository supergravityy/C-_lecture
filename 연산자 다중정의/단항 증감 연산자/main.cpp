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
		cout << "���� ������ : ++num" << endl;
		return ++(this->Data);
	}

	int operator++(int)
	{
		cout << "���� ������ : num++" << endl;
		int temp = (this->Data)++; // ���� �����ڴ� ���� ������ ���� ��ȯ�Ѵٴ� ���� ��������

		return temp;
	}

	/*----------------------------------------
	* operTest& operator(int)
	* {
	*		int data  = this->Data++ ;
	*		return *this;
	* }
	* 
	* ��õ���� ������, �̷������ε� Ȱ���� ����
	* 
	* ���ó���� cout << NUM++++++++ << endl; �̷������ε� �ڵ����� -> ����õ
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
	cout << test << endl; // �Լ�ȣ�� ������ -> test()�� �Ȱ���

	return 0;
}