#include <iostream>

int testFunc(int param)
{
	int result = param * 2;
	return result;
}

int main()
{
	int input = 0;

	std::cout << "�����Է� : ";
	std::cin >> input;

	int&& r_val = (input + 5); 
	// ����������� �ӽð�ü�� ������ (�̸� X) -> ���Կ����� �ӽð�ü�� �Ҹ�ȴ�.
	// �׷��� &&�� �ӽð�ü�� �̸��� �ο��ϰ� �Ҹ������ ���ָ� ���������� �ǻ���� ��밡���ϴ�
	std::cout << r_val << std::endl;

	int&& result = testFunc(10); // ��ȯ���� �ӽð�ü�� �ϼ���
	result += 10;
	// �Ҹ�Ǿ�� �ϴ� �ӽð�ü�� �ǻ���� ����ϰ� �ִ�.
	std::cout << result << std::endl;

	return 0;
}