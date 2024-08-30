#include <iostream>

using namespace std;

class Mydata
{
public:
	Mydata(int para) : m_Data(para)
	{
		cout << "MyData(int)" << endl;
	}

	Mydata(const Mydata& Inst) : m_Data(Inst.m_Data)
	{
		cout << "MyData(const Mydata&)" << endl;
	}

	Mydata operator + (const Mydata& Inst) const
		// ���� �ν��Ͻ��� ������ �ٲ��� �ʱ⿡ �Լ� ���ȭ
	{
		cout << "operator +" << endl;
		Mydata retval(0); // ����� �����ؾ� �ϱ⿡ �ӽð�ü ����
		retval.m_Data = this->m_Data + Inst.m_Data;
		return retval;
	}

	Mydata& operator = (const Mydata& Inst)
	{
		cout << "operator = " << endl;
		this->m_Data = Inst.m_Data;
		return *this;
	}
	// �� ��ȯ���� ��ȯ���� �̷��� �����Ǿ�� �ϳ�?
	// a = b = c = d; ���� �ڵ�� a = ( b = ( c = d )); �� ������ �۵���. 

	int getData()
	{
		return this->m_Data;
	}

private:
	int m_Data = 0;
};

Mydata operator + (int left, Mydata& Inst)
{
	cout << "global_operator +" << endl;
	Mydata data(left + Inst.getData());

	return data;
}
/*------------------------------------------
* �� �� �Լ��� �� �������� �������ִ°�?
* 
* Ŭ���� ����� ������ �Լ��� �����Ϸ��� �� ������ �Ķ���ʹ� �ݵ�� �ش�Ŭ������ �ν��Ͻ����� �Ѵ�.
* 
* �׷��� ����� �ʿ����� test1 = test2 + test3; �Ӹ� �ƴ� test1 = 3 + test2; �������ε� ��밡���ϱ⿡
* �������Լ� ��� ���Ŀ� ����ȴ�. �׷��� �������� �������ش�.
* Ȥ�� test1 = 3 + test2; �������� ������ �� �ֱ⿡, �ݴ�ε� �������־�� �Ѵ�
* 
* ����, �� ������ ��Ű�� �ʴ´ٸ� -> test1 = test2 + 3;
* 3�� �ӽð�ü�� �����ϰ�, + ������ ����Լ��� ���·� �����Ϸ��� �ٲ������. -> �ǵ�ġ ���� �ӽð�ü �� ����
* �ֳ��ϸ�, class + class ������ ����� int + class ������ ���길 ���� �Ǿ� �����⿡ �����Ϸ��� 1��° ������ �������� ������� �ٲ������ ����
------------------------------------------*/

int main()
{
	cout << "*** begin ***" << endl;

	Mydata test1(0), test2(1), test3(2);

	test1 = test2 + test3; // test1.operator=( test2.operator+(test3) )
	// ���� ���·� �ۼ��ϴ°� ���Ǽ��� �پ
	cout << test1.getData() << endl;

	test1 = 3 + test2;
	cout << test1.getData() << endl;

	cout << "*** end ***" << endl;
	return 0;
}