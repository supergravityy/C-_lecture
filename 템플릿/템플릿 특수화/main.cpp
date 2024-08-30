#include <iostream>

using namespace std;

template <typename T>

class MyData
{
public:
	MyData(T para) : mData(para) {}
	// 이런구조는 포인터변수를 받았을때 사용자의 사용에 예외를 둔다

	T getter() const { return this->mData; }
	void setter(T para) { this->mData = para; }

private:
	T mData;
};

template<> // 그래서 템플릿 사용을 중단하고
class MyData<const char*>  // 지원할 형식을 따로 명시해준다
{
public: // 그리고 메서드들을 지원하는 형식에 알맞게 다시 정의해주자
	MyData(const char* str)
	{
		size_t lenght = strlen(str);
		this->mData = new char[lenght + 1];
		strcpy_s(this->mData, lenght+1,str);
	}

	~MyData() { delete[] this->mData; }

	char* getter() const { return this->mData; }
	void setter() { /*복잡해서 생략*/ }
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