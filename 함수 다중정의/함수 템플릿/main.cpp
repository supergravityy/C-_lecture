#include <iostream>

template <typename T>

T add(T a, T b)
{
	return a + b;
	// �Լ� ���ø� ������ ����Ͽ�, ������ Ÿ�ӿ��� �Ķ������ �ڷ����� 
	// ȣ���ڰ� �ǵ��� �ٿ� ���� ���� �� �ִ�
}

int main()
{
	std::cout << add(3, 4) << std::endl;
	std::cout << add(3.3, 4.4) << std::endl;
	std::cout << add('b', 'd') - 'a' << std::endl;

	// ������ Ÿ�ӿ��� ���ø� �������� ���� add �Լ��� 3���̳� ����ȴ�.
}