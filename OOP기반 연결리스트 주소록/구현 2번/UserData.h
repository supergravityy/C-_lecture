#pragma once

#include "Node.h"
#define LENGTH 32

class UserData : public Node // 주소록을 만들기 위해 Node를 상속받음
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