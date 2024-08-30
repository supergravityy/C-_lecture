#include <iostream>

using namespace std;

class MyData
{
public:
	int nData_P = 5;
};

class MyDataEx : public MyData
{
public:
	int nData_C = 10;
};

int main()
{
	MyData* pData1 = new MyDataEx;

	// typeid �� type_info Ŭ������ ��ȯ�Ͽ�, ��ü�� ������ ��ȯ�Ѵ�.
	cout << typeid(pData1).name() << endl;
	cout << typeid(*pData1).name() << endl;

	MyDataEx* pDataEx1 = reinterpret_cast<MyDataEx*>(pData1);
	MyDataEx* pDataEx2 = (MyDataEx*)pData1;
	// reinterpret_cast�� C�� ����ȯ�� �Ȱ���.

	cout << typeid(pDataEx1).name() << endl;
	cout << typeid(*pDataEx1).name() << endl;

	// ���� ���������� �ʴµ� ������ �ؼ��ϰ� �ϸ�?
	MyData* pData2 = new MyData;
	MyDataEx* pDataEx3 = reinterpret_cast<MyDataEx*>(pData2);

	cout << pDataEx3->nData_C << endl; 
	// ���� ���ʿ� �ν��Ͻ��� �θ�ü�ε� �ڽİ�ü�� ����κ��� �ؼ��Ϸ����� -> �翬�� �����Ⱚ�� ������ ��

	delete pData1;
	delete pData2;

	return 0;
}