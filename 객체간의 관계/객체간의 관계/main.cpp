#include <iostream>
#include <string.h>

using namespace std;

class Node
{
	friend class MyList; // MyList Ŭ������ �޼���� �� Ŭ������ ���������ϴ� ����� ���ٰ����� ���� ȹ��

public:
	explicit Node(const char* Name) // explicit�� ������ ��ȯ�� ���� Ű���忴�� -> ��������
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

		while (pNode) // ���Ḯ��Ʈ ���λ���
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