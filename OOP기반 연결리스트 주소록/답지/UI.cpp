#include "UI.h"
#include "List.h"
#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>

UI::UI(List& refList) : m_List(refList)
{}

UI::~UI() {}

void UI::Add()
{
	char tempName[32] = { 0 };
	char tempPhone[32] = { 0 };

	printf("Input name : ");
	gets_s(tempName, sizeof(tempName));

	printf("Input phone number : ");
	gets_s(tempPhone, sizeof(tempPhone));

	m_List.addNewNode(tempName, tempPhone);
}

int UI::printUI()
{
	int nInput = 0;

	system("cls");
	printf("[1]Add\t[2]Search\t[3]Print all\t[4]Remove\t[0]Exit\n:");

	scanf_s("%d%*c", &nInput);

	return nInput;
}

void UI::Search()
{
	char stdName[32] = { 0 };
	UserData* pNode = NULL;

	printf("Input name : ");
	gets_s(stdName, sizeof(stdName));

	pNode = m_List.findNode(stdName);

	if (pNode != NULL)
	{
		printf("[%p] %s\t%s [%p]\n",
			pNode,
			pNode->getName(), pNode->getPhone(),
			pNode->getNext());
	}
	else
		puts("ERROR: 데이터를 찾을 수 없습니다.");
	
	_getch();
}

void UI::Remove()
{
	char stdName[32] = { 0 };

	printf("Input name : ");
	gets_s(stdName, sizeof(stdName));

	if (m_List.removeNode(stdName))
		puts("삭제완료.");
	else
		puts("ERROR: 삭제할 데이터를 찾을 수 없습니다.");

	_getch();
}

int UI::UIrun()
{
	int menu = 0;

	while ((menu = printUI()) != 0)
	{
		switch (menu)
		{
		case 1:    //Add
			Add();
			break;

		case 2:    //Search
			Search();
			break;

		case 3:    //Print all
			m_List.printAll();
			break;

		case 4:    //Remove
			Remove();
			break;
		}
	}

	return menu;
}