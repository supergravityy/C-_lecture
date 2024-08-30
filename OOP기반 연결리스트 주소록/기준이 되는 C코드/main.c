#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 32
#define PHONE_LEN 32

void releaseList();
void flushBuff();

typedef struct _USERDATA
{
	char Name[NAME_LEN];
	char Phone[PHONE_LEN];

	struct _USERDATA* pNext;
} USERDATA;

USERDATA g_Head = { 0 };

USERDATA* findNode_Name(const char* stdName)
{
	USERDATA* pTemp = g_Head.pNext;

	while (pTemp != NULL)
	{
		if (strcmp(pTemp->Name, stdName) == 0)
			return pTemp;

		pTemp = pTemp->pNext;
	}

	return NULL;
}

int add_newNode(const char* newName, const char* newPhone)
{
	USERDATA* pNewUser = NULL;

	// 중복 사용자 확인
	if (findNode_Name(newName) != NULL)
		return 0;

	pNewUser = (USERDATA*)malloc(sizeof(USERDATA));
	memset(pNewUser, 0, sizeof(USERDATA));

	sprintf_s(pNewUser->Name, sizeof(pNewUser->Name), "%s", newName);
	sprintf_s(pNewUser->Phone, sizeof(pNewUser->Phone), "%s", newPhone);
	pNewUser->pNext = NULL;

	// 더미노드 바로 뒤에 붙인다.

	pNewUser->pNext = g_Head.pNext;
	g_Head.pNext = pNewUser;

	return 1;
}

void addUser()
{
	char newName[NAME_LEN] = { 0 };
	char newPhone[PHONE_LEN] = { 0 };

	printf("이름입력 : ");
	gets_s(newName, NAME_LEN);
	flushBuff();

	printf("\n번호입력 : ");
	gets_s(newPhone, PHONE_LEN);
	flushBuff();

	add_newNode(newName, newPhone);
}

void flushBuff()
{
	while (getchar() != NULL);
}

void searchUser()
{
	char stdName[32] = { 0 };
	USERDATA* findNode = NULL;

	printf("이름입력 : ");
	gets_s(stdName, NAME_LEN);
	flushBuff();

	findNode = findNode_Name(stdName);
	if (findNode != NULL)
		printf("[%p] : %s\t%s\n", findNode, findNode->Name, findNode->Phone);
	else
		printf("데이터를 찾을 수 없습니다.");

	_getch();
}

void printAll()
{
	USERDATA* pTemp = g_Head.pNext;

	while (pTemp != NULL)
	{
		printf("[%p] : %s\t%s\n", pTemp, pTemp->Name, pTemp->Phone);
		
		pTemp = pTemp->pNext;
	}

	_getch();
}

int removeNode(char* stdName)
{
	USERDATA* prevNode = &g_Head;
	USERDATA* delNode = NULL;

	while (prevNode->pNext != NULL)
	{
		delNode = prevNode->pNext;

		if (strcmp(delNode->Name, stdName) == 0)
		{
			prevNode->pNext = delNode->pNext;
			free(delNode);

			return 1;
		}
		prevNode = prevNode->pNext;
	}
	return 0;
}

void removeUser()
{
	char findName[NAME_LEN] = { 0 };

	printf("이름입력 : ");
	gets_s(findName, sizeof(findName));
	flushBuff();

	if (removeNode(findName))
		printf("삭제완료!");
	else
		printf("대상이 없습니다!");
	
	_getch();
}

int printUI()
{
	int input = 0;

	system("cls");
	printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

	scanf_s("%d%*c", &input);

	return input;
}

void releaseList()
{
	USERDATA* pTemp = g_Head.pNext;
	USERDATA* pDel = NULL;

	while (pTemp != NULL)
	{
		pDel = pTemp;
		pTemp = pTemp->pNext;

		free(pDel);
	}

	memset(&g_Head, 0, sizeof(USERDATA));
}

void main()
{
	int nMenu = 0;

	// 메인 이벤트 반복문
	while ((nMenu = printUI()) != 0) {
		switch (nMenu) {
		case 1:		  
			addUser();
			break;

		case 2:		  
			searchUser();
			break;

		case 3:		 
			printAll();
			break;

		case 4:		  
			removeUser();
			break;
		}
	}

	releaseList();
}