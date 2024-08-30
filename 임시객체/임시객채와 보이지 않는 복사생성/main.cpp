#include <iostream>

using namespace std;

class TestData
{
public:
	TestData(const int data) : nData(data) // ��ȯ������ (���߿� ��ﳻ��)
	{
		cout << "TestData(int)" << endl;
	}

	TestData(const TestData& temp) : nData(temp.nData)
	{
		cout << "TestData(const TestData&)" << endl;
	}

	~TestData()
	{
		cout << "~TestData(" << nData << ")" << endl;
		// �Ҹ��, ��������Ͱ� �������� �˷���
	}

	int getData() const
	{
		return nData;
	}

	void setData(const int data)
	{
		this->nData = data;
	}

private:
	int nData = 0;
};

TestData testFunc(TestData tempInst) 
// ȿ������ ���� ����������� �Ķ���ʹ�, ��ȯ�ܿ� �Ѵ� ���� �ʾҴ�
{
	cout << "testFunc()" << endl;
	tempInst.setData(20);
	return tempInst;
}

TestData testFunc2(TestData& tempInst) // �����̶� ������ ���ϱ� ����
{
	cout << "testFunc()" << endl;
	tempInst.setData(20);
	return tempInst;
}

int main()
{
	cout << "1�� �׽�Ʈ" << endl;

	testFunc(10).setData(100); // �Ķ���ͷ� 10�� �ذ��� TestData temp(10) �� ����. 
	/*-----
	* ����
	* 
	* 1. TestData�� �ӽ� �ν��Ͻ��� �ڵ����� -> ������ �߿� ���� �ϳ��� ������ ��������� �ʱ�ȭ��Ű�� �Լ� ����
	* 2. testFunc�� �ش� �ӽ� �ν��Ͻ��� �Ű������� ���� -> �ӽð�ü ������ 
	* 3. testFunc�� ��ȯ�� ��, �Ǵٽ� �ӽ� �ν��Ͻ��� �Ű������� ���� -> �ӽð�ü ������ -> �Ű����� �ӽð�ü �Ҹ��
	* 4. �ݷ����� ��ȯ�� �ȹ��� -> ��ȯ �ӽð�ü ������ X -> �Ҹ�
	* 
	* �������� ���� : C++�� ȿ������ ���ϴ� ���α׷��� ����ε�, ��ü�����Ҹ��� ���������� �Ͼ�� �Ǵ°� ��ȿ���� ������ �ƴѰ�?
	-----*/

	cout << "2�� �׽�Ʈ" << endl;

	TestData result = testFunc(10); // ������ �� ��ȯ �ӽð�ü�� result�� �������� ����
	result.setData(300);

	cout << "3�� �׽�Ʈ" << endl;

	TestData result2 = testFunc2(result); // ���� �׽�Ʈ�Լ��� �Ķ���ʹ� �ִ� ����� ���������� �޴´� -> ������ ȣ�� X
	// �׷���, 1��ó�� �׳� ����� ������ �Ķ���ͷ� �ѱ��, �ӽð�ü ������
	result.setData(1000);

	cout << "�����Լ� ����" << endl;
	return 0;
}