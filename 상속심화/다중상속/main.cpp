#include<iostream>

using namespace std;

class Shape
{
public:
	Shape(int type) : m_type(type)
	{
		cout << "Shape ������" << endl;
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
		cout << "Image ������" << endl;
	}

	int getHeight() const { return this->m_height; }
	int getWidth() const { return this->m_width; }

protected:
	int m_height;
	int m_width;
};

class Picture : public Image, public Shape // �� �θ�Ŭ������ public ���ֱ�
{
public:
	Picture(int width, int height, int type) : Image(width, height), Shape(type)
	// ���߻���� �޾ұ⿡, �θ�Ŭ�������� �����ڸ� �����Ų��.
	{
		cout << "Picture ������" << endl;
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