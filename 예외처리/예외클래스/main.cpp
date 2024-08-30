#include <iostream>

using namespace std;

class MyException // �̷������� ���ܸ��� ���� ��ü�� �������ָ� ������ �ſ� ��
{
public:
	MyException(int nCode, const char* Msg)
	{
		this->errCode = nCode;
		strcpy_s(this->errMsg, sizeof(this->errMsg), Msg);
	}

	int getErrCode() const
	{
		return this->errCode;
	}

	const char* getMsg() const
	{
		return this->errMsg;
	}
private:
	int errCode;
	char errMsg[128];
};

int main()
{
	try
	{
		int input = 0;
		cout << "�ڿ��� �Է� : ";
		cin >> input;

		if (input <= 0) // catch ���� �þ���� �ʿ䰡 ���� 
		{
			MyException exp(10, "�ڿ����� �Է��Ұ�"); // �����ڵ� 10
			throw exp;
		}
	}
	catch (MyException& exp)
	{
		cout << "�����ڵ� [" << exp.getErrCode() << "], �����޽��� : "
			<< exp.getMsg() << endl;
	}
}