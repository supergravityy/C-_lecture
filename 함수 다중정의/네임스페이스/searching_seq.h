#pragma once

#include<iostream>

using namespace std;

namespace Test
{
	int data = 100;

	void testFunc()
	{
		cout << "그냥 data로 사용시, Test소속의 data가 출력 : " << data << endl;
		cout << "::data로 사용시, 전역소속의 data가 출력 : " << ::data << endl;
	}
}