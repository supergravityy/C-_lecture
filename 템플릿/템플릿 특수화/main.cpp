#include <iostream>

using namespace std;

template <typename T>

class MyData
{
public:
	MyData(T para) : mData(para) {}
	// �̷������� �����ͺ����� �޾����� ������� ��뿡 ���ܸ� �д�

	T getter() const { return this->mData; }
	void setter(T para) { this->mData = para; }

private:
	T mData;
};

template<> // �׷��� ���ø� ����� �ߴ��ϰ�
class MyData<const char*>  // ������ ������ ���� ������ش�
{
public: // �׸��� �޼������ �����ϴ� ���Ŀ� �˸°� �ٽ� ����������
	MyData(const char* str)
	{
		size_t lenght = strlen(str);
		this->mData = new char[lenght + 1];
		strcpy_s(this->mData, lenght+1,str);
	}

	~MyData() { delete[] this->mData; }

	char* getter() const { return this->mData; }
	void setter() { /*�����ؼ� ����*/ }
private:
	char* mData = nullptr;
};

int main()
{
	MyData<int> testTemplate1(20);

	MyData<const char*> testTemplate2("Hello World!");
	cout << testTemplate2.getter() << endl;

	return 0;
}