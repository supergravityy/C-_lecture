#include "List.h"
#include <cstdio>
#include <cstring>
#include <conio.h>


List::List()
{}

List::~List()
{
	releaseList();
}

int List::addNewNode(const char* newName, const char* newPhone)
{
	UserData* pNewUser = nullptr;

	if (findNode(newName) != nullptr)
		return 0;

	pNewUser = new UserData;
	strcpy_s(pNewUser->Name, sizeof(pNewUser->Name), newName);
	strcpy_s(pNewUser->Phone, sizeof(pNewUser->Phone), newPhone);
	pNewUser->pNext = NULL;

	pNewUser->pNext = m_Head.pNext;
	m_Head.pNext = pNewUser;

	return 1;
}

void List::printAll()
{
	UserData* pTemp = m_Head.pNext;

	while (pTemp != NULL)
	{
		printf("[%p] %s\t%s [%p]\n",
			pTemp, pTemp->Name, pTemp->Phone, pTemp->pNext);

		pTemp = pTemp->pNext;
	}

	printf("UserData Cnt : %d\n", UserData::getUserDataCounter() - 1);
	_getch();
}

UserData* List::findNode(const char* stdName)
{
	UserData* pTemp = m_Head.pNext;

	while (pTemp != nullptr)
	{
		if (strcmp(pTemp->Name, stdName) == 0)
			return pTemp;

		pTemp = pTemp->pNext;
	}

	return nullptr;
}

int List::removeNode(const char* stdName)
{
	UserData* prevNode = &m_Head;
	UserData* tgtNode = NULL;

	while (prevNode->pNext != nullptr)
	{
		tgtNode = prevNode->pNext;

		if (strcmp(tgtNode->Name, stdName) == 0)
		{
			prevNode->pNext = tgtNode->pNext;
			delete tgtNode;

			return 1;
		}

		prevNode = prevNode->pNext;
	}
	return 0;
}

void List::releaseList()
{
	UserData* tempNode = m_Head.pNext;
	UserData* tgtNode = nullptr;

	while (tempNode != nullptr)
	{
		tgtNode = tempNode;
		tempNode = tempNode->pNext;

		delete tgtNode;
	}

	m_Head.pNext = nullptr;
}