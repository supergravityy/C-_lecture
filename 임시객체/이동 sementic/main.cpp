#include <iostream>

using namespace std;

class TestData
{
public:
	TestData()
	{
		cout << "TestData()" << endl;
		this->nData = new int(0);
	}

	TestData(const TestData& temp) // deepcopy
	{
		cout << "TestData(const TestData&)" << endl;
		this->setData(temp.getData());
	}

	TestData(TestData&& Rval) noexcept // shallowcopy (�̵�������)

	// noexcept -> ����ó���� �߻����� ���� [���������� ������ ������]
	{
		cout << "TestData(TestData&&) - move" << endl;
		delete this->nData;				// �� �����͸���� �� ����Ű�� �ϴ� ���� (�޸� ���� ����)
		this->nData = Rval.nData;		// �ӽð�ü�� ������ �ּҸ� �����Ͷ�
		Rval.nData = nullptr;			// �ӽð�ü �����͸���� ��ó�� -> free�� delete�� NULL�� �ްԵǸ� ����ȵ� (�ش翵�� ����)
	}

	~TestData() noexcept // ����/�Ҹ� ������ �����ϸ� �ȵ� -> ����ó���� ������
	{
		cout << "~TestData()" << endl;
		delete this->nData;
	}

	void operator = (TestData& temp)
	// ������ �ؿ� ó�� ���Կ����ڸ� �ٽ� �����, ��ȯ���� �����ν��Ͻ��� ���� ������ ��ȯ�ϰ� �ؾ���
	{
		cout << "operator=(TestData&)" << endl;
		setData(temp.getData());
	}

	TestData& operator = (TestData&& Rval) noexcept // shallowcopy (�̵� ���� ������)
	// �̵������� �� �̵����Կ����ڴ� ����ٴ�!!! -> ���μ����ؼ� �����ų�, ���������� �����ų� �� �����̴�.
	{
		cout << "operator=(TestData&&) - move" << endl;
		delete this->nData;
		this->nData = Rval.nData;
		Rval.nData = nullptr;

		return *this; // ������ �����ڷ� ��ȯ�� (L��) -> C++���� ��������� �����ϱ⿡
	}

	/*
	* ���� ��, 
	TestData A,B,C ;
	A = B = C = getTestData(53); 
	�̷������� ��������� �����ϱ����� ���� ���� ��ȯ���� �ʿ��ϴ�.
	*/

	/*
	* TestData& operator=(TestData&& rhs) noexcept {
		cout << "operator=(TestData&&) - move" << endl;
		delete pnData;
		pnData = rhs.pnData;
		rhs.pnData = nullptr;
		return *this;
	}
	����� �̷��� �ᵵ��.
	*/

	int getData() const
	{
		return *nData;
	}

	void setData(int data)
	{
		if (nData != nullptr)
			delete nData;
		nData = new int;
		*nData = data;
	}

private:
	int* nData = nullptr;
};

TestData getTestData(int para)
{
	cout << "getTestData()" << endl;
	TestData test;

	test.setData(para);
	return test;
}

int main()
{
	cout << "*** Before ***" << endl;

	TestData t1 = getTestData(5); // �̷��� �ڵ�� �����Ϸ��� ����ȭ ���Ѽ� �ӽð�ü�� ����/�Ҹ��� �� �� ����

	TestData t2(std::move(getTestData(10))); // std::move �Լ��� ���� ����ȭ�� �������� �� �� �ִ�.

	TestData t3(t2); // ��������ڷ� t2�� ������ ��ī���ߴ�

	TestData result;
	result = getTestData(15); // �ӽð�ü Rval ���� ���Կ����ڸ� �������Ͽ� ���� ������ �̵���Ŵ (43������ �ڵ�)

	cout << "*** after ***" << endl;
	return 0;
}