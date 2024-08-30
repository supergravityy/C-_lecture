#include <iostream>

using namespace std;

class MyData
{
public:
	int nData_P = 5;
};

class MyDataEx : public MyData
{
public:
	int nData_C = 10;
};

int main()
{
	MyData* pData1 = new MyDataEx;

	// typeid 는 type_info 클래스를 반환하여, 객체의 정보를 반환한다.
	cout << typeid(pData1).name() << endl;
	cout << typeid(*pData1).name() << endl;

	MyDataEx* pDataEx1 = reinterpret_cast<MyDataEx*>(pData1);
	MyDataEx* pDataEx2 = (MyDataEx*)pData1;
	// reinterpret_cast는 C의 형변환과 똑같다.

	cout << typeid(pDataEx1).name() << endl;
	cout << typeid(*pDataEx1).name() << endl;

	// 만약 존재하지도 않는데 강제로 해석하게 하면?
	MyData* pData2 = new MyData;
	MyDataEx* pDataEx3 = reinterpret_cast<MyDataEx*>(pData2);

	cout << pDataEx3->nData_C << endl; 
	// 지금 애초에 인스턴스가 부모객체인데 자식객체의 멤버부분을 해석하려고함 -> 당연히 쓰래기값이 나오게 됨

	delete pData1;
	delete pData2;

	return 0;
}