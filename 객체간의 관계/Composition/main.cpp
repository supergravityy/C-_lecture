#include <iostream>
#include <conio.h>

using namespace std;

class Node
{
	friend class MyList;

public:
	explicit Node(const char* Name)
	{
		strcpy_s(this->m_Name, sizeof(this->m_Name), Name);
	}

private:
	char m_Name[32];
	Node* m_Next = nullptr;
};

class MyList
{
public:
	MyList() : m_HeadNode("Dummy Head") {}
	~MyList()
	{
		Node* tempNode = this->m_HeadNode.m_Next;
		Node* targetDelete = nullptr;

		while (tempNode)
		{
			targetDelete = tempNode;
			tempNode = tempNode->m_Next;
			delete targetDelete;
		}
		this->m_HeadNode.m_Next = nullptr;
	}

	void appendNode(const char* Name)
	{
		Node* tempNode = new Node(Name);

		tempNode->m_Next = this->m_HeadNode.m_Next;
		this->m_HeadNode.m_Next = tempNode;
	}

	void printAll()
	{
		Node* tempNode = this->m_HeadNode.m_Next;
		while (tempNode)
		{
			cout << tempNode->m_Name << endl;
			tempNode = tempNode->m_Next;
		}
	}

private:
	Node m_HeadNode;
	// ���ó� Node ��ü�� List ��ü�� �κ��������� ���踦 ������.
};

class MyUI
{
public:
	int printMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
		cout.flush();
		int input = 0;
		cin >> input;

		return input;
	}

	void runMenu()
	{
		char Name[32];
		int input = 0;

		while ((input = printMenu()) > 0)
		{
			switch (input) 
			{
			case 1:
				cout << "�̸� : ";
				cout.flush();
				cin >> Name;
				m_list.appendNode(Name);
				break;

			case 2:	
				m_list.printAll();
				_getch();
				break;
		
			default:
				break;
			}
		}
	}
private:
	MyList m_list;
	// Aggregation ����� �ٸ��� List�� UI�� �������̴�.
	// Aggregation ���迡�� List�� ���������� ����Ǿ�����.
	// Composition ���迡�� list��ü�� ui�� �ν��Ͻ��̴�.
};

int main()
{
	MyUI ui;
	ui.runMenu();
}