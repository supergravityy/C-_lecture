#include <iostream>

using namespace std;

class MyData
{
public :
	MyData()
	{}
	~MyData()
	{}
	void setData(int para)
	{
		this->m_Data = para;
	}
	int getData()
	{
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
		if (para < 0)
			MyData::setData(0);
		else if (para > 10)
			MyData::setData(10);
		else
			MyData::setData(para);
	}

	// �θ��� Data ��������� �����̺��̱⿡ �ڽĵ� ���� ����
	// �׷��� -> "�θ���ӽ����̽�"::"�θ�޼���"()
	// �� ����ؼ�, �������̵� ���� �޼��嵵 ����� �����ϴ�.
};

int main()
{
	MyData test1;

	test1.setData(20);

	MyDataEx test2;
	test2.setData(15);

	cout << "test1(parents) : " << test1.getData() << endl;
	cout << "test2(child) : " << test2.getData() << endl;
	
}