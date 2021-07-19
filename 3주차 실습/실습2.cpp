#include <iostream>

class SetValue
{
	int x, y;
	
public:
	void setXY(int X, int Y) {
		this->x = X;
		this->y = Y;
	}

	void show() {
		std::cout << "X = " << this->x << ", Y = " << this->y << std::endl;
	}
};
int main()
{
	SetValue obj;
	obj.setXY(33, 44);
	obj.show();
	system("pause");
	return 0;
}