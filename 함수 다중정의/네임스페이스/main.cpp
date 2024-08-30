int data = 200;
// 식별자 검색순서를 확인하기 위함. -> global 네임스페이스
// 역시나 컴파일의 절차때문에 위에다가 선언 하였다.

#include "searching_seq.h"




namespace Win_dev
// 네임스페이스는 중첩해서도 사용이 가능하다 -> 선언방식은 C++17 이전버전은 이렇게
// 밖에다가 해당 함수를 정의할 수도 있다 -> 대신에 함수선언시 네임스페이스를 엄격하게 작성해줄것
{
	namespace gnrl_dev
	{
		namespace userApi
		{
			int depth_level = 3; 
			// 역시나 컴파일 과정은 절차지향적이기 때문에 printDepth 함수에서 쓰려면 먼저 사용해줘야 한다. 

			void print_Depth()
			{
				std::cout << "userAPi의 깊이출력함수입니다. 깊이 : " << depth_level << std::endl;
			}
			void print_Location();
		}

		int depth_level = 2;

		void print_Depth()
		{
			std::cout << "generalDev의 깊이출력함수입니다. 깊이 : " << depth_level << std::endl;
		}
		void print_Location();
		
	}

	int depth_level = 1;

	void print_Depth()
	{
		std::cout << "WinDev의 깊이출력함수입니다. 깊이 : " << depth_level << std::endl;
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

	std::cout << "식별자 검색순서를 알아보기 위한 부분" << std::endl;

	Test::testFunc();
	return 0;
}