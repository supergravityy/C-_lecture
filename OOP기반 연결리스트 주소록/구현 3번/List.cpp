#include "List.h"
#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

List::List(Node* pHead) { this->m_Head = pHead; }

List::~List() { releaseList(); }

int List::addNewNode(Node* pNewNode)
{
	if (findNode(pNewNode->getKey()) != nullptr)
	{
		delete pNewNode;
		return 0;
	}

	if (onAddNewNode(pNewNode)) // 욕설필터링
	{
		pNewNode->pNext = this->m_Head->pNext;
		this->m_Head->pNext = pNewNode;
		return 1;
	}
	return -1;
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

void List::releaseList(void)
{
	Node* tempNode = m_Head;
	Node* tgtNode = NULL;

	while (tempNode != NULL)
	{
		tgtNode = tempNode;
		tempNode = tempNode->pNext;

		delete tgtNode;
	}

	this->m_Head = NULL;
}

Iterator List::makeIterator()
{
	Iterator it;
	it.m_Current = this->m_Head->pNext; // 더미헤드 버림
	it.m_Head = this->m_Head->pNext;

	return it;
}

int List::onAddNewNode(Node* pNewNode)
{
	return 1;
}