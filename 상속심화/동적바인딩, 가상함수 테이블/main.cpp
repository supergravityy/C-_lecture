#include <iostream>

using namespace std;

class Parents // Vtable�� �������� ���� -> ������� this�������� ���뿡 __vfptr ��� �迭�� Ȯ���ϸ� ��
{
public:
	Parents()
	{cout << "�θ� ������" << endl;} // �ڽ� �ν��Ͻ��� ����Ǹ鼭 ������� ����Ǵ� ������ -> vfptr�� ��ҵ��� �θ�޼���� ������Ʈ��

	virtual ~Parents()
	{cout << "�θ� �Ҹ���" << endl;}

	virtual void test1()
	{cout << "�θ�::�׽�Ʈ1" << endl;}

	virtual void test2()
	{cout << "�θ�::�׽�Ʈ2" << endl;}
};

class Child : public Parents
{
public:
	Child()
	{cout << "�ڽ� ������" << endl;} // �� �������� ����Ǵ� ������ -> vfptr�� ��ҵ��� �ڽĸ޼���� ������Ʈ��

	~Child()
	{cout << "�ڽ� �Ҹ���" << endl;}

	void test1()
	{cout << "�ڽ�::�׽�Ʈ1" << endl;}

	void test2()
	{cout << "�ڽ�::�׽�Ʈ2" << endl;}
};

int main()
{
	Parents* forTest = new Child;

	return 0; 
}