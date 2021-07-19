#include <iostream>
#include <string>

template <typename T>
auto sum(T x) {
	return x;
}

template<typename T, typename...Args>
auto sum(T x, Args... args) {
	return x + sum(args...);
}
int main() {
	auto x = sum(42.5, 10, 11.1f);
	std::cout << x;
	getchar();
}

/* 에러 발생 이유 : auto sum(T x, Args... args)는 인자가 최소 2개 필요한 함수입니다.
* 처음에는 인자가 3개여서 일단 42.5와 10 두개는 받아서 처리할 수 있었는데,
* 11.1f를 받을 땐 인자가 하나밖에 남지 않아서 함수가 정상적으로 기능할 수 없습니다.
* 따라서 auto sum(T x)를 추가해주어 인자가 하나 남았을 때 처리를 해주었습니다.
*/