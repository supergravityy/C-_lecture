int data = 200;
// �ĺ��� �˻������� Ȯ���ϱ� ����. -> global ���ӽ����̽�
// ���ó� �������� ���������� �����ٰ� ���� �Ͽ���.

#include "searching_seq.h"




namespace Win_dev
// ���ӽ����̽��� ��ø�ؼ��� ����� �����ϴ� -> �������� C++17 ���������� �̷���
// �ۿ��ٰ� �ش� �Լ��� ������ ���� �ִ� -> ��ſ� �Լ������ ���ӽ����̽��� �����ϰ� �ۼ����ٰ�
{
	namespace gnrl_dev
	{
		namespace userApi
		{
			int depth_level = 3; 
			// ���ó� ������ ������ �����������̱� ������ printDepth �Լ����� ������ ���� �������� �Ѵ�. 

			void print_Depth()
			{
				std::cout << "userAPi�� ��������Լ��Դϴ�. ���� : " << depth_level << std::endl;
			}
			void print_Location();
		}

		int depth_level = 2;

		void print_Depth()
		{
			std::cout << "generalDev�� ��������Լ��Դϴ�. ���� : " << depth_level << std::endl;
		}
		void print_Location();
		
	}

	int depth_level = 1;

	void print_Depth()
	{
		std::cout << "WinDev�� ��������Լ��Դϴ�. ���� : " << depth_level << std::endl;
	}
	void print_Location();
}

void Win_dev::print_Location()
{
	std::cout << "::Win_dev" << std::endl;
}

void Win_dev::gnrl_dev::print_Location()
{
	std::cout << "::Win_dev::gnrl_dev" << std::endl;
}

void Win_dev::gnrl_dev::userApi::print_Location()
{
	std::cout << "::Win_dev::gnrl_dev::userApi" << std::endl;
}

int main()
{
	Win_dev::print_Depth();
	Win_dev::print_Location();
	Win_dev::gnrl_dev::print_Depth();
	Win_dev::gnrl_dev::print_Location();
	Win_dev::gnrl_dev::userApi::print_Depth();
	Win_dev::gnrl_dev::userApi::print_Location();

	std::cout << "�ĺ��� �˻������� �˾ƺ��� ���� �κ�" << std::endl;

	Test::testFunc();
	return 0;
}