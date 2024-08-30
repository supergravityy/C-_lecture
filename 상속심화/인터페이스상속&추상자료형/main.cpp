#include <iostream>

using namespace std;

class Myobj
{
public:
	Myobj() {}
	virtual ~Myobj() {}

	virtual int getDeviceID() = 0;

protected:
	int m_deviceID;
};

class MyTV : public Myobj
{
public:
	MyTV(int id)
	{
		this->m_deviceID = id;
	}

	virtual int getDeviceID()
	{
		cout << "MyTV::getDeviceID" << endl;
		return this->m_deviceID;
	}
};

class MyPhone : public Myobj
{
public:
	MyPhone(int id)
	{
		this->m_deviceID = id;
	}
	
	virtual int getDeviceID()
	{
		cout << "MyPhone::getDeviceID" << endl;
		return this->m_deviceID;
	}
};

void printID(Myobj* pobj) // 추상자료형으로 받고있음
{
	cout << "Device ID : " << pobj->getDeviceID() << endl;
	// 겟디바이스 메서드가 가상이기에, 파생메서드가 호출된다. -> 인터페이스가 여러 파생클래스를 지원한다
}

int main()
{
	MyTV tv(5);
	MyPhone phone(12);

	::printID(&tv);
	::printID(&phone);

	return 0;
}