#include <iostream>

using namespace std;

int C_StyleERR()
{
	// C ��Ÿ�� ����ó��

	int a = 100, b;
	cout << "�����Է� : ";
	cin >> b;

	if (b == 0)
		goto ERR; // ��������� goto�� �̿��ؿԴ�

	cout << a / b << endl;
	return 0;

ERR:
	cout << "0���� ������ ����" << endl;
	return -1;
}

int Cpp_StyleERR()
{
	// C++ ��Ÿ�� ����ó��

	int a = 100, b;
	cout << "�����Է� : ";
	cin >> b;

	try // �����ϴ� �κ�
	{
		if (b == 0)
			throw b; // ���ܽ� ���ܻ�Ȳ�� ����
		else
			cout << a / b << endl;
	}
	catch (int err_num) // �ش� ���ܻ�Ȳ�� �޾Ƽ� �׿� �´� ó��
	{
		cout << err_num << "���� ���� �� ����" << endl;
	}
	return 0;
}

int main()
{
	C_StyleERR();

	Cpp_StyleERR();
}