#include <iostream>

#define X_LIM 100
#define Y_LIM 200
#define Z_LIM 150

using namespace std;

class MyLoc
{
public:
	MyLoc(int x)
	{
		cout << "My location(int)" << endl;
		if (x > X_LIM)
			x = X_LIM;
		
		this->x = x;
	}

	MyLoc(int x, int y) : MyLoc(x)
	{
		cout << "My location(int,int)" << endl;
		if (y > Y_LIM)
			y = Y_LIM;

		this->y = Y_LIM;
	}

	MyLoc(int x, int y, int z) : MyLoc(x,y)
	{
		cout << "My location(int,int,int)" << endl;
		if (z > Z_LIM)
			z = Z_LIM;

		this->z = Z_LIM;
	}

	void print()
	{
		cout << "x : " << this->x << endl;
		// this 포인터를 안써줘도 컴파일러가 알아서 우선순위에 의해 결정함
		
		if(y > 0)
			cout << "y : " << this->y << endl;

		if(z > 0)
			cout << "z : " << this->z << endl;
	}

private:
	int x = -1, y = -1, z = -1;
};

int main()
{
	MyLoc begin(110);
	begin.print();

	MyLoc begin2(50, 250);
	begin2.print();

	MyLoc begin3(50, 175, 195);
	begin3.print();

	return 0;
}