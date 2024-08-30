#include <iostream>

using namespace std;

class MyInterface // ��������Ŭ���� = �������̽� Ŭ���� -> �ν��Ͻ� ���� ��ü�� �ȵ�
{
public:
	MyInterface()
	{
		cout << "MyInterface()" << endl;
	}

	virtual int getData() const = 0; // �������� �޼��� ����
	virtual void setData(int para) = 0;
};

class MyData : public MyInterface
{
public:
	MyData()
	{
		cout << "MyData()" << endl;
	}

	virtual int getData() const
	{
		return this->m_Data;
	}
	virtual void setData(int para)
	{
		this->m_Data = para;
	}
private:
	int m_Data = 0;
};

int main()
{
	//MyInterface Inst; //�ν��Ͻ� ���� �Ұ���
	MyData Inst;
	Inst.setData(25);
	cout << Inst.getData() << endl;

	return 0;
}