#include <iostream>

void testFunc(int a, int b)
{
	std::cout << "�Ű����� �ΰ�!" << std::endl;
}

void testFunc(int a, int b, int c = 10)
{
	std::cout << "�Ű����� �ΰ� + default 1��!" << std::endl;
}

int main()
{
	//testFunc(2, 1); 
	// �̷��� ��쿡�� ������ �ܰ迡�� ���� �ΰ�,���� �Լ��� ���� �Ұ� -> ������ ���� �߻�

	testFunc(1, 2, 3);

	return 0;
}