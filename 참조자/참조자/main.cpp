#include <iostream>

int main()
{
	int data(10);

	int& ref = data; // �����ڴ� ����� ���ÿ� �ʱ�ȭ�� �ɰ�
	ref = 20;
	std::cout << ref << std::endl; // �޸� ������ ����, �����Ϳ� �Ȱ��� ��Ŀ�������� �۵��Ѵ�

	int* pnt = &data;
	*pnt = 30;
	std::cout << *pnt << std::endl;

	std::cout << "�ּ����" << std::endl;
	std::cout << "&data : " << &data << std::endl;
	std::cout << "&ref : " << &ref << std::endl; // �����ڿ� &�� �ٿ��� ��½�, ��������� �ּҰ��� ����Ŵ 
	std::cout << "&pnt : " << &pnt << std::endl;

	return 0;
}