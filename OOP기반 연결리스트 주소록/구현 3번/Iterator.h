#pragma once

#include "Node.h"

class Iterator // 외부에서 아예 자료구조에 대한 접근을 차단
{
	friend class List;

public:
	Iterator() : m_Head(nullptr), m_Current(nullptr) {}
	~Iterator() {}

	Node* getCurrent() const { return this->m_Current; }
	void MoveNext()
	{
		if (this->m_Current != nullptr)
			this->m_Current = this->m_Current->getNext();
	}

private:
	Node* m_Head;
	Node* m_Current;
};