#include "ListEx.h"
#include <cstdio>
#include <cstring>
#include <conio.h>

ListEx::ListEx(Node* pHead) : List(pHead) {}
ListEx::~ListEx() {}

int ListEx::onAddNewNode(Node* pNewNode) // 자시클래스에서 오버라이드됨
{
	// 문자열 필터링 기능
	if (strcmp(pNewNode->getKey(), "개새끼") == 0)
		return 0;

	return 1;
}