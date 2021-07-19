#include <iostream>

class Setvalue {
public:
	int x, y;

};

int main() {

	Setvalue obj;

	obj.x = 33;
	obj.y = 44;
	std::cout << "X= " << obj.x << " , Y= " << obj.y << std::endl;
	system("pause");
	return 0;
}