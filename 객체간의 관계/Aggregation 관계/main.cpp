#include <iostream>
#include <conio.h>

using namespace std;

// 노드를 객체로 선언하였다.
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

// 기능을 모아놓은 객체 -> C의 연결리스트에서도 헤드와 테일을 저장하는 구조체가 존재하였다.
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
	Node m_HeadNode; // 해드노드는 그냥 더미노드이다(가리키는 다음노드가 실질적인 헤드)
	// 이 헤드노드를 선언함으로써, Node 객체는 MyList에 의존적임 -> 부분집합 관계
};

// UI 객체
class MyUI
{
public:
	// 참조 멤버는 반드시 초기화 목록을 이용해 초기화 할것
	MyUI(MyList& refList) : m_list(refList) {}

	// 메뉴 출력 및 사용자 입력을 확인
	int printMenu()
	{
		system("cls");
		cout << "[1]Add\t" << "[2]Print\t" << "[0]Exit\n:";
		cout.flush();
		
		int input = 0;
		cin >> input;

		return input;
	}

	// 지속적으로 메뉴를 출력하는 메인이벤트 반복문
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
	// UI 클래스 내부에는 자료구조 객체에 대한 참조만 존재
	// UI, List 객체는 서로 필요에 의해 결합됨 -> 분리해도 가능 (의존성 ↓)
	// 그러나 Node 객체는 List 객체의 부분집합적인 관계
};

int main()
{
	MyList list;
	MyUI ui(list);

	ui.runMenu();

	return 0;
}