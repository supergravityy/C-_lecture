#include <iostream>

using namespace std;

class Shape
{
public:
	Shape() {}
	virtual ~Shape() {}
	virtual void Draw()
	{
		cout << "Shape::Draw" << endl;
	}
};

class Rect : public Shape
{
public:
	virtual void Draw()
	{
		cout << "Rect::Draw" << endl;
	}
};

class Circ : public Shape
{
public:
	virtual void Draw()
	{
		cout << "Circ::Draw" << endl;
	}
};

int main()
{
	cout << "도형번호를 입력하시오" << endl;
	int input = 0;
	cin >> input;

	Shape* pShape = nullptr;

	if (input == 1)
		pShape = new Rect;
	else if (input == 2)
		pShape = new Circ;
	else
		pShape = nullptr;

	pShape->Draw();
	
	/*--------------다이나믹 캐스팅---------------*/
	// 지금 내가 선택한게 어떠한 파생클래스인지 확인하는 작업 -> 여기선 하향식 형변환을 하는중

	Rect* pRect = dynamic_cast<Rect*>(pShape);

	if (pRect != NULL)
		cout << "Rect::Draw" << endl;
	else
	{
		Circ* pCirc = dynamic_cast<Circ*>(pShape);

		if (pCirc != NULL)
			cout << "Circ::Draw" << endl;
		else
			cout << "Shape::Draw" << endl;
	}
	
	cout << typeid(*pShape).name() << endl;

	return 0;
}