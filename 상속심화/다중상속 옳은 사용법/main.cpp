class CMyUSB // ��������Ŭ����
{
public:
	virtual int GetUsbVersion() = 0;
	virtual int GetTransferRate() = 0;
};

class CMySerial // ��������Ŭ����
{
public:
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
// ���� ����̽� �ڽ�Ŭ������ �� �θ�Ŭ������ �޼��� ������ å��������
{
public:
	// USB �������̽�
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	// �ø��� �������̽�
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int main()
{
	CMyDevice dev;
}
