#pragma once

class List;

class UI
{
public:
	UI(List& refList);

	~UI();

	void Add();

	void Search(void);

	void Remove(void);

	void printAll(void);

	int printUI(void);

	int runUI(void);

protected:
	List& m_List;
};