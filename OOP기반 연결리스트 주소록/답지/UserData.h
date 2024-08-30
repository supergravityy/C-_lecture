#pragma once

class UserData
{
	friend class List;

public:
	UserData();
	~UserData();

	const char* getName() const { return this->Name; }
	const char* getPhone() const { return this->Phone; }
	const UserData* getNext() const { return this->pNext; }

	static int getUserDataCounter() { return UserData::UserDataCnt; }
protected:
	char Name[32];
	char Phone[32];

	UserData* pNext;
	static int UserDataCnt;
};