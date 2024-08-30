#include <iostream>
#include <string.h>

using namespace std;

class Node
{
	friend class MyList; // MyList 클래스의 메서드는 이 클래스의 접근제어하는 멤버에 접근가능한 권한 획득

public:
	explicit Node(const char* Name) // explicit은 묵시적 변환을 막는 키워드였다 -> 잊지말자
	{
		strcpy_s( this->name, sizeof(this->name), Name);
	}

private:
	char name[32];
	Node* pNext = nullptr;
};

class MyList
{
public:
	MyList(): headNode("Dummy Head") {}
	~MyList()
	{
		Node* pNode = headNode.pNext;
		Node* pDelete = nullptr;

		while (pNode) // 연결리스트 전부삭제
		{
			pDelete = pNode;
			pNode = pNode->pNext;

			cout << pDelete->name << endl;
			delete pDelete;
		}
	}

	void addNewNode(const char* Name)
	{
		Node* pNode = new Node(Name);

		pNode->pNext = headNode.pNext;
		headNode.pNext = pNode;
	}

private:
	Node headNode;

};