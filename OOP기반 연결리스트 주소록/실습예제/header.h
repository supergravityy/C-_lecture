#pragma once

#include <iostream>
#include <conio.h>

#define NAME_LEN 32
#define PHONE_LEN 32

using namespace std;

class Node
{
public:
	Node()
	{
		cout << "������" << endl;
	}

	/*---setter---*/

	void set_Name(const char* newName);
	
	void set_Phone(const char* newPhone);
	
	void set_NextAddr(Node* nextAddr);

	/*---getter---*/

	char* get_Name();

	char* get_Phone();

	Node* get_NextAddr();


private:
	char mName[NAME_LEN] = { 0 };
	char mPhone[PHONE_LEN] = { 0 };
	Node* mNext = nullptr;
};

class UI; // friend�� �ϱ����� �̸� ������ �����Ϸ����� �˷��ٰ�

class List
{
	friend class UI;
public:
	List()
	{
		cout << "����Ʈ����" << endl;
	}

private:
	int addNode(const char* newName, const char* newPhone);

	Node* findNode(const char* stdName);

	int removeNode(const char* stdName);

	Node* getHead();

	int getCount();

	void deleteNode();


	Node* mHead = NULL;
	int m_countNode = 0;
};

class UI
{
public:
	UI(List& list) : m_MyList(list)
	{
		cout << "UI ����" << endl;
	}

	void runUI();

private:

	void addMan();

	void searchMan();

	void printAll();

	void removeMan();

	void releaseList();
	
	int printUI();
	
	List& m_MyList;
};