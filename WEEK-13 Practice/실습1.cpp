#include <iostream>

template <typename T, int num = 5>

T add_num(T t) {
	return t + num;
}
int main() {
	int x = 3;
	std::cout << "x : " << add_num(x - 3) << std::endl;
}

// 리턴이 t + 2가 되도록하려면 add_num()의 매개변수에 3을 빼주면 된다.