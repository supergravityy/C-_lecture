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
	cout << "������ȣ�� �Է��Ͻÿ�" << endl;
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
	
	/*--------------���̳��� ĳ����---------------*/
	// ���� ���� �����Ѱ� ��� �Ļ�Ŭ�������� Ȯ���ϴ� �۾� -> ���⼱ ����� ����ȯ�� �ϴ���

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