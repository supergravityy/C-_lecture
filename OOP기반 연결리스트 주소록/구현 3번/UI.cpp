#include "UI.h"
#include "List.h"
#include "UserData.h"
#include "Iterator.h"

#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

UI::UI(List &refList) : m_List(refList) {}

UI::~UI() {}

void UI::Add()
{
	char inputName[32] = { 0 };
	char inputPhone[32] = { 0 };

	printf("Input name : ");
	gets_s(inputName, sizeof(inputName));

	printf("Input phone number : ");
	gets_s(inputPhone, sizeof(inputPhone));

	int result = this->m_List.addNewNode(new UserData(inputName, inputPhone));

	if (result == 0)
	{
		puts("ERROR: 이미 존재하는 데이터입니다.");
		_getch();
	}

	else if (result == -1)
	{
		puts("ERROR: 욕설을 이름으로 쓸 수 없습니다.");
		_getch();
	}
}

int UI::printUI()
{
	int input = 0;

	system("cls");
	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n:");

	scanf_s("%d%*c", &input);

	return input;
}

void UI::Search()
{
	char stdName[32] = { 0 };
	UserData* stdNode = nullptr;

	printf("Input name : ");
	gets_s(stdName, sizeof(stdName));

	// findNode의 반환값은 부모클래스형식이기에 컴파일타임에서 하향식 형변환
	stdNode = static_cast<UserData*>(this->m_List.findNode(stdName));

	if (stdNode != nullptr)
	{
		printf("[%p] %s\t%s [%p]\n",
			stdNode, stdNode->getName(), stdNode->getPhone(), stdNode->getNext());
	}
	else
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	_getch();
}

void UI::Remove()
{
	char tgtName[32] = { 0 };

	printf("Input name : ");
	gets_s(tgtName, sizeof(tgtName));

	if (this->m_List.removeNode(tgtName))
		puts("삭제완료.");
	else
		puts("ERROR: 삭제할 데이터를 찾을 수 없습니다.");
	_getch();
}

void UI::printAll(void) // 이전의 printAll이 List에서 UI로 옮겨짐 -> 이게 맞다
{
	Iterator it = m_List.makeIterator();
	UserData* pNode = nullptr;

	while ((pNode = static_cast<UserData*>(it.getCurrent())) != nullptr)
	{
		pNode->printNode();
		it.MoveNext();
	}

	_getch();
}

int UI::runUI()
{
	int nMenu = 0;
	while ((nMenu = printUI()) != 0)
	{
		switch (nMenu)
		{
		case 1:    //Add
			Add();
			break;

		case 2:    //Search
			Search();
			break;

		case 3:    //Print all
			printAll();
			break;

		case 4:    //Remove
			Remove();
			break;
		}
	}

	return nMenu;
}