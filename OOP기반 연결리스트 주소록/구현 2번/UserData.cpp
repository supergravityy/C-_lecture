#include "UserData.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

int UserData::UserDataCnt = 0;

UserData::UserData()
{
	memset(this->Name, 0, sizeof(this->Name));
	memset(this->Phone, 0, sizeof(this->Phone));

	UserData::UserDataCnt++;
}

UserData::UserData(const char* newName, const char* newPhone) 
{
	memset(this->Name, 0, sizeof(this->Name));
	memset(this->Phone, 0, sizeof(this->Phone));

	strcpy_s(this->Name, sizeof(this->Name), newName);
	strcpy_s(this->Phone, sizeof(this->Phone), newPhone);

	UserData::UserDataCnt++;
}

UserData::~UserData()
{
	UserData::UserDataCnt--;
}

const char* UserData::getKey() // ����� �̸��� Ű�̴�.
{
	return this->Name;
}

void UserData::printNode()
{
#ifdef _DEBUG // debug ���� �����Ͻ� �̰� �����
	printf("[%p] %s\t%s [%p]\n",
		this, this->Name, this->Phone, getNext());
#else
	printf("%s\t%s\n", szName, szPhone);
#endif
}