#include "ListEx.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

ListEx::ListEx(Node* pHead) : List(pHead) {}
ListEx::~ListEx() {}

int ListEx::onAddNewNode(Node* pNewNode) // �ڽ�Ŭ�������� �������̵��
{
	// ���ڿ� ���͸� ���
	if (strcmp(pNewNode->getKey(), "������") == 0)
		return 0;

	return 1;
}