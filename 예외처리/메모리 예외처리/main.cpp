#include <iostream>
#include <new>

using namespace std;

// �����۾� : x64�� �ƴ� x86���� �õ� (��밡���� �޸𸮶���)

// ������Ȳ 1. size�� �����Է�
// ������Ȳ 2. size���� 1.7G �̻� �ۼ��غ���

class Test
{
public:
	Test(int size) // ���⼭ size�� �����϶��� ����÷ΰ� �߻� -> unsigned�� �ٲ�� ���� ���� ��
	{
		this->mData = new char[size];
		cout << "�Ҵ缺��!" << endl;
	}
	~Test()
	{
		delete[] this->mData;
		cout << "��������!" << endl;
	}

private:
	char* mData;
};

int main()
{
	try
	{
		int memSize;
		cout << "�Է»����� : ";
		cin >> memSize;
		
		Test temp(memSize);
	}
	catch (bad_alloc& exp) // bad_alloc Ŭ������ std�ȿ� ����.
	{
		cout << exp.what() << endl;
		cout << "Err : Test �ν��Ͻ� ��������" << endl;
	}

	return 0;
}