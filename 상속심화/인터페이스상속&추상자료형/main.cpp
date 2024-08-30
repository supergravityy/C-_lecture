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

void printID(Myobj* pobj) // �߻��ڷ������� �ް�����
{
	cout << "Device ID : " << pobj->getDeviceID() << endl;
	// �ٵ���̽� �޼��尡 �����̱⿡, �Ļ��޼��尡 ȣ��ȴ�. -> �������̽��� ���� �Ļ�Ŭ������ �����Ѵ�
}

int main()
{
	MyTV tv(5);
	MyPhone phone(12);

	::printID(&tv);
	::printID(&phone);

	return 0;
}