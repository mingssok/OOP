#include <iostream>
bool funcA() {
	int c;
	std::cout << "input(number) : ";
	std::cin >> c;
	if (c < 10) //Let's assume this is exception
		throw std::out_of_range("invalid Input!!");

	return true; // = 1
}
int main() {

	try // != 0
	{
		funcA();
	}
	catch (std::out_of_range& e) {
		std::cout << "Exception : "<< e.what() << std::endl;
	}
	return 0;
}