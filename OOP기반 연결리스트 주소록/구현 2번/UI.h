#pragma once

class List;

class UI
{
public:
	UI(List& refList);
	~UI();
	void Add();

protected:
	List& m_list;

public:
	void Search();

	void Remove();

	int printUI();

	int runUI();
};