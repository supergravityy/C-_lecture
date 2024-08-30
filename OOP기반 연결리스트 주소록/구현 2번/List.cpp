#include "List.h"
#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

List::List(Node* Head)
{
	this->m_Head = Head;
}

List::~List()
{
	releaseList();
}

int List::addNewNode(Node* newNode) // 애초에 파라미터단에서 새로운 노드를 생성하고 그를 추가시킴
{
	if (findNode(newNode->getKey()) != nullptr)
	{
		delete newNode;
		return 0;
	}

	newNode->pNext = this->m_Head->pNext;
	this->m_Head->pNext = newNode;

	return 1;
}

void List::printAll()
{
	Node* pTemp = this->m_Head->pNext;

	while (pTemp != nullptr)
	{
		pTemp->printNode();
		pTemp = pTemp->pNext;
	}

	printf("CUserData Counter : %d\n", UserData::getUserDataCounter() - 1);
	_getch();
}

Node* List::findNode(const char* myKey)
{
	Node* pTemp = this->m_Head->pNext;

	while (pTemp != nullptr)
	{
		if (strcmp(pTemp->getKey(), myKey) == 0)
			return pTemp;

		pTemp = pTemp->pNext;
	}

	return nullptr;
}

int List::removeNode(const char* myKey)
{
	Node* prevNode = this->m_Head;
	Node* tgtNode = nullptr;

	while (prevNode->pNext != nullptr)
	{
		tgtNode = prevNode->pNext;

		if (strcmp(tgtNode->getKey(), myKey) == 0)
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
	Node* pTemp = this->m_Head;
	Node* tgtNode = nullptr;

	while (pTemp != nullptr)
	{
		tgtNode = pTemp;
		pTemp = pTemp->pNext;

		delete tgtNode;
	}

	this->m_Head = nullptr;
}