#include<iostream>

using namespace std;

class Shape
{
public:
	Shape(int type) : m_type(type)
	{
		cout << "Shape 생성자" << endl;
	}

	int getType() const { return this->m_type; }

private:
	int m_type;
};

class Image
{
public:
	Image(int height, int width) : m_height(height), m_width(width)
	{
		cout << "Image 생성자" << endl;
	}

	int getHeight() const { return this->m_height; }
	int getWidth() const { return this->m_width; }

protected:
	int m_height;
	int m_width;
};

class Picture : public Image, public Shape // 각 부모클래스에 public 써주기
{
public:
	Picture(int width, int height, int type) : Image(width, height), Shape(type)
	// 다중상속을 받았기에, 부모클래스들의 생성자를 실행시킨다.
	{
		cout << "Picture 생성자" << endl;
	}
};

int main()
{
	Picture pic(200,450,1);

	cout << "Width: " << pic.getWidth() << endl;
	cout << "Height: " << pic.getHeight() << endl;
	cout << "Type: " << pic.getType() << endl;

	return 0;
}