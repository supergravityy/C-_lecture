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
	// 역시나 Node 객체는 List 객체의 부분집합적인 관계를 가진다.
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
				cout << "이름 : ";
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
	// Aggregation 관계와 다르게 List는 UI에 종속적이다.
	// Aggregation 관계에선 List가 참조형으로 선언되었었다.
	// Composition 관계에선 list자체가 ui의 인스턴스이다.
};

int main()
{
	MyUI ui;
	ui.runMenu();
}