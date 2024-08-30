#include "UserData.h"
#include <cstdio>

int UserData::UserDataCounter = 0;

UserData::UserData() { UserData::UserDataCounter++; }

UserData::UserData(const char* newName, const char* newPhone) : Name(newName), Phone(newPhone)
{ UserData::UserDataCounter++; }

UserData::~UserData() { UserData::UserDataCounter--; }

const char* UserData::getKey() { return this->Name.c_str(); }

void UserData::printNode()
{
#ifdef _DEBUG
	printf("[%p] %s\t%s [%p]\n",
		this, this->Name.c_str(), this->Phone.c_str(), getNext());
#else
	printf("%s\t%s\n", szName, szPhone);
#endif
}