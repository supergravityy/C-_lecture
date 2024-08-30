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
		puts("ERROR: �̹� �����ϴ� �������Դϴ�.");
		_getch();
	}

	else if (result == -1)
	{
		puts("ERROR: �弳�� �̸����� �� �� �����ϴ�.");
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

	// findNode�� ��ȯ���� �θ�Ŭ���������̱⿡ ������Ÿ�ӿ��� ����� ����ȯ
	stdNode = static_cast<UserData*>(this->m_List.findNode(stdName));

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
	char tgtName[32] = { 0 };

	printf("Input name : ");
	gets_s(tgtName, sizeof(tgtName));

	if (this->m_List.removeNode(tgtName))
		puts("�����Ϸ�.");
	else
		puts("ERROR: ������ �����͸� ã�� �� �����ϴ�.");
	_getch();
}

void UI::printAll(void) // ������ printAll�� List���� UI�� �Ű��� -> �̰� �´�
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