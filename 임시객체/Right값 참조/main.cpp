#include <iostream>

using namespace std;

void testFunc(int& val)
{
	cout << "testFunc(int&)" << endl;
}

void testFunc(int&& val) // r�� ���� : 
{
	cout << "testFunc(int&&)" << endl;
}

//void testFunc(int val)
//{
//	cout << "testFunc(int)" << endl;
//}

// �ش� �Լ��� �ּ��� Ǯ��, ������ �߻� -> �Լ� �������ǿ��� �����Ϸ��� �ݷ��� ���ǿ� �����ϴ� �Լ��� �ڵ����� �Ⱦ�������,
// �̿Ͱ��� �Լ��� ���縦 �ؿ��⿡, r�� l�� �����Լ� �ΰ��� ��ü�� ���� �ֱ⿡ ������ �߻���Ŵ 
// �����Ϸ� : �׷��� �� �����Ұǵ�....

int main()
{
	testFunc(3 + 4);
	testFunc(12);

	int A = 10;
	testFunc(A);

	return 0;
}