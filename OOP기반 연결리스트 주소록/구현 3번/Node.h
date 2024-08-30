#pragma once

class Node
{
	friend class List;

public:
	Node();
	virtual ~Node();

	Node* getNext() const { return pNext; }

	virtual const char* getKey() = 0;
	virtual void printNode() = 0;

private:
	Node* pNext;
};