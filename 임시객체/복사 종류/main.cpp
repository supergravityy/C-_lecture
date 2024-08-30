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
	TestCopy(TestCopy& temp) // ���� ���簡 �̷����
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
		// �Ҹ����� ������ �����ϱ� ����
		TestCopy B(0);
		B.print();
		{
			TestCopy A(20);
			TestCopy C(B);
			A.print(); 
			C.print(); // C�� B�� ���� ���� �ٸ� ���� ����

			B = A; // �ڷ����� �Ȱ��� ��, ���� ��������� ���� ����� -> ���� ����
			B.print(); // A�� data����� ����Ű�� �ּҸ� ���Ե�
		}
	}// �ش�κп��� B�� �Ҹ��ڰ� ����ǰ� ������ ����Ŵ.
	
}