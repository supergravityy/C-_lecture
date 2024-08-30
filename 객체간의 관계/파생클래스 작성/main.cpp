#include <iostream>

using namespace std;

class MyData // �θ�Ŭ����
{
public:
	MyData()
	{
		cout << "MyData()" << endl;
	}
	
	int getData()
	{
		return this->m_Data;
	}

	void setData(int para)
	{
		this->m_Data = para;
	}

protected:
	void printData()
	{
		cout << "MyData::PrintData()" << endl;
	}

private:
	int m_Data = 0;
};

class MyDataEx : public MyData
{
public:
	MyDataEx()
	{
		cout << "MyDataEx()" << endl;
	}

	void testFunc(int para)
	{
		// �θ�Ŭ���� �޼��忡�� ������ ����
		printData();
		setData(para);

		// ���߿� ������ �������̵��� ���ؼ�, �������� namespace�� ���ִ� ���� ����
		cout << MyData::getData() << endl;
	}
};

int main()
{
	MyDataEx data;

	data.setData(10);
	cout << data.getData() << endl;

	data.testFunc(25);


	// ���� ������ �ƴϴ�!
	MyData* pData = new MyDataEx; // �Ļ����Ŀ� ���� �ν��Ͻ��� ����������, �⺻�������� �����ϴ� ��� -> �߻��ڷ���

	pData->setData(51);
	// pData->testFunc(53) => �߻��ڷ������� �θ�Ŭ������ �����Ͽ��� ������ �ڽ��� �޼��带 ���Ұ�
	delete pData;
}