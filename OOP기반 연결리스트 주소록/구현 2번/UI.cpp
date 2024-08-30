#include <cstdio>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include "UI.h"
#include "List.h"
#include "UserData.h"

#define LENGTH 32

UI::UI(List& refList) : m_list(refList) {}

UI::~UI() {}

void UI::Add()
{
	char inputName[LENGTH] = { 0 };
	char inputPhone[LENGTH] = { 0 };

	printf("Input name : ");
	gets_s(inputName, sizeof(inputName));

	printf("Input phone number : ");
	gets_s(inputPhone, sizeof(inputPhone));

	UserData* newData = new UserData(inputName, inputPhone);

	this->m_list.addNewNode(newData);
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
	char stdName[LENGTH] = { 0 };
	UserData* stdNode = nullptr;

	printf("Input name : ");
	gets_s(stdName, sizeof(stdName));

	// findNode�� ��ȯ���� �θ�Ŭ���������̱⿡ ������Ÿ�ӿ��� ����� ����ȯ
	stdNode = static_cast<UserData*>(this->m_list.findNode(stdName)); 

	if (stdNode != nullptr)
	{
		printf("[%p] %s\t%s [%p]\n",
			stdNode, stdNode->getName(), stdNode->getPhone(), stdNode->getNext());
	}
	else
		puts("ERROR: �����͸� ã�� �� �����ϴ�.");
	_getch();
}

void UI::Remove()
{
	char tgtName[LENGTH] = { 0 };

	printf("Input name : ");
	gets_s(tgtName, sizeof(tgtName));

	if (this->m_list.removeNode(tgtName))
		puts("�����Ϸ�.");
	else
		puts("ERROR: ������ �����͸� ã�� �� �����ϴ�.");
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
			this->m_list.printAll();
			break;

		case 4:    //Remove
			Remove();
			break;
		}
	}

	return nMenu;
}