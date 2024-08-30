#include "header.h"

/***********************************
* Node ���Ǻ�
***********************************/

void Node::set_Name(const char* newName)
{
	memset(this->mName, 0, NAME_LEN);
	strcpy_s(this->mName, NAME_LEN, newName);
}

void Node::set_Phone(const char* newPhone)
{
	memset(this->mPhone, 0, PHONE_LEN);
	strcpy_s(this->mPhone, PHONE_LEN, newPhone);
}

void Node::set_NextAddr(Node* nextAddr)
{
	this->mNext = nextAddr;
}

char* Node::get_Name()
{
	return this->mName;
}

char* Node::get_Phone()
{
	return this->mPhone;
}

Node* Node::get_NextAddr()
{
	return this->mNext;
}

/***********************************
* List ���Ǻ�
***********************************/

int List::addNode(const char* newName, const char* newPhone)
{
	if (findNode(newName) != NULL)
	{
		cout << "�̹� �����ϴ� ����Դϴ�" << endl;
		return 0;
	}

	Node* tempNode = new Node;

	tempNode->set_Name(newName);
	tempNode->set_Phone(newPhone);
	tempNode->set_NextAddr(NULL); // ù��� �����ø� ����

	tempNode->set_NextAddr(this->mHead); // �Ӹ��� ���̱�
	this->mHead = tempNode;
	this->m_countNode += 1;

	return 1;
}

Node* List::findNode(const char* stdName)
{
	Node* tempNode = this->mHead;

	while (tempNode != NULL)
	{
		if (strcmp(tempNode->get_Name(), stdName) == 0)
			return tempNode;

		tempNode = tempNode->get_NextAddr();
	}

	return NULL; // ��ã��
}

int List::removeNode(const char* stdName)
{
	Node* prevNode = this->mHead;
	Node* targetNode = nullptr;

	if (strcmp(prevNode->get_Name(), stdName) == 0)
	{
		targetNode = this->mHead;
		this->mHead = this->mHead->get_NextAddr();
		delete targetNode;

		this->m_countNode -= 1;
		return 1;
	}

	while (prevNode->get_NextAddr() != NULL)
	{
		targetNode = prevNode->get_NextAddr();

		if (strcmp(targetNode->get_Name(), stdName) == 0)
		{
			prevNode->set_NextAddr(targetNode->get_NextAddr());
			free(targetNode);

			this->m_countNode -= 1;

			return 1;
		}

		prevNode = prevNode->get_NextAddr();
	}

	return 0;
}

Node* List::getHead()
{
	return this->mHead;
}

int List::getCount()
{
	return this->m_countNode;
}

void List::deleteNode()
{
	Node* tempNode = this->mHead;
	this->mHead = this->mHead->get_NextAddr();
	this->m_countNode -= 1;

	delete tempNode;
}
/***********************************
* UI ���Ǻ�
***********************************/

void UI::runUI()
{
	int input = 0;

	while ((input = this->printUI()) != 0)
	{
		switch (input)
		{
		case 1:
			this->addMan();
			break;
		case 2:
			this->searchMan();
			break;
		case 3:
			this->printAll();
			break;
		case 4:
			this->removeMan();
			break;

		default:
			break;
		}
	}

	this->releaseList();
}

void UI::addMan()
{
	char newName[NAME_LEN] = { 0 };
	char newPhone[PHONE_LEN] = { 0 };

	cout << "�̸��Է� : ";
	cin >> newName;
	cout << endl << "��ȣ�Է� : ";
	cin >> newPhone;
	cout << endl;

	this->m_MyList.addNode(newName, newPhone);
}

void UI::searchMan()
{
	char stdName[32] = { 0 };
	Node* targetNode = nullptr;

	cout << "�̸��Է� : ";
	cin >> stdName;
	cout << endl;

	targetNode = this->m_MyList.findNode(stdName);
	if (targetNode != nullptr)
		printf("[%p] : %s\t%s\n", targetNode, targetNode->get_Name(), targetNode->get_Phone());
	else
		cout << "�����͸� ã�� �� ����\n�ƹ�Ű�� ������ ���θ޴��� ����" << endl;

	_getch();
}

void UI::printAll()
{
	Node* tempNode = this->m_MyList.getHead();

	while (tempNode != NULL)
	{
		printf("[%p] : %s\t%s\n", tempNode, tempNode->get_Name(), tempNode->get_Phone());
		tempNode = tempNode->get_NextAddr();
	}

	cout << "�� �ο��� : " << this->m_MyList.getCount() << endl;

	cout << "�ƹ�Ű�� ������ ���θ޴��� ����" << endl;
	_getch();
}

void UI::removeMan()
{
	if (this->m_MyList.getCount() < 1)
	{
		cout << "�ο�����. �ƹ�Ű�� ������ ���θ޴��� ����" << endl;
		_getch();
		return;
	}

	char findName[NAME_LEN] = { 0 };

	cout << "�̸��Է� : ";
	cin >> findName;
	cout << endl;

	if (this->m_MyList.removeNode(findName))
		cout << "��� �����Ϸ�!" << endl;
	else
		cout << "��� Ž���Ұ�!" << endl;

	cout << "�ƹ�Ű�� ������ ���θ޴��� ����" << endl;
	_getch();
}

void UI::releaseList()
{
	while (m_MyList.getCount() > 0)
		m_MyList.deleteNode();
}

int UI::printUI()
{
	int input = 0;

	system("cls");
	cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:";
	cin >> input;
	cout << endl;

	return input;
}