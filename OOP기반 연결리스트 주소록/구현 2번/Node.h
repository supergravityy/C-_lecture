#pragma once
class Node // 해당 노드는 상속을 위해 필요맞게 변경하는 부모클래스
{
	friend class List;

public:
	Node();
	virtual ~Node();
	Node* getNext() const { return pNext; }

	// 관리를 위해 꼭 필요한 인터페이스 함수들을 순수 가상 함수로 선언

	virtual const char* getKey() = 0; // 자료구조의 고유식별자를 반환
	virtual void printNode() = 0;

private:
	Node* pNext; // 일단 연결리스트이기 때문
};
