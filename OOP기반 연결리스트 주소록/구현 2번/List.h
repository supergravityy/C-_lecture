#pragma once

#include "Node.h"

// 노드 클래스에 대한 알림선언
class Node;

class List
{
public:
	List(Node* Head);
	~List();

protected:
	void releaseList();
	Node* m_Head;

public:
	Node* findNode(const char* myKey);
	int addNewNode(Node* newNode);
	void printAll();
	int removeNode(const char* myKey);
};