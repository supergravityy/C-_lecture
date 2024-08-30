#include <iostream>

using namespace std;

class MyData // 부모클래스
{
public:
	MyData()
	{
		cout << "MyData()" << endl;
	}
	
	int getData()
	{
		return this->m_Data;
	}

	void setData(int para)
	{
		this->m_Data = para;
	}

protected:
	void printData()
	{
		cout << "MyData::PrintData()" << endl;
	}

private:
	int m_Data = 0;
};

class MyDataEx : public MyData
{
public:
	MyDataEx()
	{
		cout << "MyDataEx()" << endl;
	}

	void testFunc(int para)
	{
		// 부모클래스 메서드에도 접근이 가능
		printData();
		setData(para);

		// 나중에 연산자 오버라이딩을 위해서, 정식으로 namespace를 써주는 팁도 존재
		cout << MyData::getData() << endl;
	}
};

int main()
{
	MyDataEx data;

	data.setData(10);
	cout << data.getData() << endl;

	data.testFunc(25);


	// 밑은 오류가 아니다!
	MyData* pData = new MyDataEx; // 파생형식에 대한 인스턴스를 선언하지만, 기본형식으로 참조하는 경우 -> 추상자료형

	pData->setData(51);
	// pData->testFunc(53) => 추상자료형으로 부모클래스로 참조하였기 때문에 자식의 메서드를 사용불가
	delete pData;
}