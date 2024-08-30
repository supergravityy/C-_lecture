#pragma once

#include "UserData.h"

class List
{
public:
	List();
	~List();

protected:
	void releaseList();
	UserData m_Head;

public:
	UserData* findNode(const char* stdName);
	int addNewNode(const char* newName, const char* newPhone);

	void printAll();
	int removeNode(const char* stdName);
};