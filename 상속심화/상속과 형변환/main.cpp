#include <iostream>

using namespace std;

class MyData
{
public:
	MyData() {}
	virtual ~MyData() {}

	void setData(int para) 
	{ 
		cout << "�θ� setter" << endl;
		this->m_Data = para;
	}
	int getData() 
	{
		cout << "�θ� getter" << endl;
		return this->m_Data;
	}
private:
	int m_Data = 0;
};

class MyDataEx : public MyData
{
public:
	void setData(int para)
	{
		cout << "�ڽ� setter" << endl;
		if (para > 10) para = 10;
		else if (para < 0) para = 0;

		MyData::setData(para);
	}

	void printData()
	{
		cout << "�ڽ� getter" << endl;
		cout << "��� : " << this->getData() << endl;
	}
};

int main()
{
	MyData* p_Data = new MyDataEx; // �߻��ڷ������� ������
	MyDataEx* p_newData = nullptr;

	p_Data->setData(15); // �׳� ���Ը� ��
	cout << p_Data->getData() << endl;

	p_newData = static_cast<MyDataEx*>(p_Data); // ����ĳ����
	// ������ p_Data�� �޸𸮻� �θ�Ŭ���������� ������������, ����ĳ������ �����ν�, �ڽ�Ŭ���� �κб��� ���� ������
	// ���� ����� �� �����ͺ����� ����Ű���� ����Ű�� ������ �ٸ���.

	p_newData->setData(20);
	p_newData->printData();

	delete p_Data;
	return 0;
}