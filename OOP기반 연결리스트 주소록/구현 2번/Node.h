#pragma once
class Node // �ش� ���� ����� ���� �ʿ�°� �����ϴ� �θ�Ŭ����
{
	friend class List;

public:
	Node();
	virtual ~Node();
	Node* getNext() const { return pNext; }

	// ������ ���� �� �ʿ��� �������̽� �Լ����� ���� ���� �Լ��� ����

	virtual const char* getKey() = 0; // �ڷᱸ���� �����ĺ��ڸ� ��ȯ
	virtual void printNode() = 0;

private:
	Node* pNext; // �ϴ� ���Ḯ��Ʈ�̱� ����
};
