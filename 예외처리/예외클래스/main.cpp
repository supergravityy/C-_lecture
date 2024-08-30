#include <iostream>

using namespace std;

class MyException // 이런식으로 예외만을 위한 객체를 선언해주면 협업시 매우 편리
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
		cout << "자연수 입력 : ";
		cin >> input;

		if (input <= 0) // catch 문을 늘어놓을 필요가 없음 
		{
			MyException exp(10, "자연수를 입력할것"); // 에러코드 10
			throw exp;
		}
	}
	catch (MyException& exp)
	{
		cout << "에러코드 [" << exp.getErrCode() << "], 에러메시지 : "
			<< exp.getMsg() << endl;
	}
}