#pragma once

#include "Node.h"
#define LENGTH 32

class UserData : public Node // �ּҷ��� ����� ���� Node�� ��ӹ���
{
public:
	UserData();
	UserData(const char* newName, const char* newPhone);
	~UserData();

	const char* getName() const { return this->Name; }
	const char* getPhone() const { return this->Phone; }
	static int getUserDataCounter() { return UserData::UserDataCnt; }

protected:
	char Name[LENGTH];
	char Phone[LENGTH];

	static int UserDataCnt;

public:
	virtual const char* getKey();
	virtual void printNode();
};