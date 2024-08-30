#include <iostream>
#include <conio.h>

using namespace std;

// ��带 ��ü�� �����Ͽ���.
class Node
{
	friend class MyList;

public:
	explicit Node(const char* Name)
	{
		strcpy_s(this->m_Name, sizeof(m_Name), Name);
	}
private:
	char m_Name[32];
	Node* m_Next = nullptr;
};

// ����� ��Ƴ��� ��ü -> C�� ���Ḯ��Ʈ������ ���� ������ �����ϴ� ����ü�� �����Ͽ���.
class MyList
{
public:
	MyList() : m_HeadNode("Dummy Head") {}
	~MyList()
	{
		Node* nextNode = this->m_HeadNode.m_Next;
		Node* targetDelete = nullptr;

		while (nextNode)
		{
			targetDelete = nextNode;
			nextNode = nextNode->m_Next;
			delete targetDelete;
		}
		this->m_HeadNode.m_Next = nullptr;
	}

	void appendNode(const char* Name)
	{
		Node* tempNode = new Node(Name);

		tempNode->m_Next = this->m_HeadNode.m_Next;
		m_HeadNode.m_Next = tempNode;
	}

	void printAll()
	{
		Node* tempNode = m_HeadNode.m_Next;
		while (tempNode)
		{
			cout << tempNode->m_Name << endl;
			tempNode = tempNode->m_Next;
		}
	}
private:
	Node m_HeadNode; // �ص���� �׳� ���̳���̴�(����Ű�� ������尡 �������� ���)
	// �� ����带 ���������ν�, Node ��ü�� MyList�� �������� -> �κ����� ����
};

// UI ��ü
class MyUI
{
public:
	// ���� ����� �ݵ�� �ʱ�ȭ ����� �̿��� �ʱ�ȭ �Ұ�
	MyUI(MyList& refList) : m_list(refList) {}

	// �޴� ��� �� ����� �Է��� Ȯ��
	int printMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
		cout.flush();
		
		int input = 0;
		cin >> input;

		return input;
	}

	// ���������� �޴��� ����ϴ� �����̺�Ʈ �ݺ���
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

				this->m_list.appendNode(Name);
				break;

			case 2:
				this->m_list.printAll();
				_getch();
				break;

			default:
				break;
			}
		}
	}

private:
	MyList& m_list; 
	// UI Ŭ���� ���ο��� �ڷᱸ�� ��ü�� ���� ������ ����
	// UI, List ��ü�� ���� �ʿ信 ���� ���յ� -> �и��ص� ���� (������ ��)
	// �׷��� Node ��ü�� List ��ü�� �κ��������� ����
};

int main()
{
	MyList list;
	MyUI ui(list);

	ui.runMenu();

	return 0;
}