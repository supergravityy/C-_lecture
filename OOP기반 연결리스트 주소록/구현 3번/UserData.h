#pragma once

#include "Node.h"
#include <string>

using namespace std;

// Node 클래스의 파생 클래스로 변경
class UserData : public Node
{
public:
	UserData();
	UserData(const char* newName, const char* newPhone);
	~UserData();

	const char* getName() const { return this->Name.c_str(); }
	const char* getPhone() const { return this->Phone.c_str(); }
	static int getUserDataCounter() { return UserData::UserDataCounter; }

protected:
	string Name;
	string Phone;
	static int UserDataCounter;

public:
	virtual const char* getKey();
	virtual void printNode();
};
