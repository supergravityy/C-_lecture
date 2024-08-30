#pragma once
#include "Node.h"
#include "Iterator.h"

class List
{
public:
	List(Node* pHead);
	~List();

protected:
	void releaseList();
	Node* m_Head;

public:
	Node* findNode(const char* myKey);
	int addNewNode(Node* pNewNode);

	int removeNode(const char* myKey);

	Iterator makeIterator();

	virtual int onAddNewNode(Node* pNewNode);
};