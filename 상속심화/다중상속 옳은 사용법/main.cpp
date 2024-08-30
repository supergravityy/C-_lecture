class CMyUSB // 순수가상클래스
{
public:
	virtual int GetUsbVersion() = 0;
	virtual int GetTransferRate() = 0;
};

class CMySerial // 순수가상클래스
{
public:
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
// 이제 디바이스 자식클래스는 두 부모클래스의 메서드 구현을 책임져야함
{
public:
	// USB 인터페이스
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }

	// 시리얼 인터페이스
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

int main()
{
	CMyDevice dev;
}
