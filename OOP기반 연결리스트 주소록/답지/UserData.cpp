#include "UserData.h"
#include <cstring>

int UserData::UserDataCnt = 0;

UserData::UserData() : pNext(nullptr)
{
	memset(this->Name, 0, sizeof(this->Name));
	memset(this->Phone, 0, sizeof(this->Phone));

	UserData::UserDataCnt++;
}

UserData::~UserData()
{
	UserData::UserDataCnt--;
}