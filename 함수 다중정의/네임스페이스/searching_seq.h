#pragma once

#include<iostream>

using namespace std;

namespace Test
{
	int data = 100;

	void testFunc()
	{
		cout << "�׳� data�� ����, Test�Ҽ��� data�� ��� : " << data << endl;
		cout << "::data�� ����, �����Ҽ��� data�� ��� : " << ::data << endl;
	}
}