#pragma once

#include "List.h"

class ListEx : public List
{
public:
	ListEx(Node* pHead);
	~ListEx();
	virtual int onAddNewNode(Node* pNewNode);
};