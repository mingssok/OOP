#include <iostream>
#include <stdexcept>
class Test {
public:
	Test(char id) : id_(id) {}
	~Test() {
		std::cout << "Destructor execution: "
			<< id_ << std::endl;
	}
private:
	char id_;
};
int funcB() {
	Test r('B');
	throw std::runtime_error("Exception from funcB!\n");
	std::cout << "Executed in B" << std::endl;
	return 0;
}
int funcA() {
	Test r('A');
	funcB();
	std::cout << "Executed in A" << std::endl;
	return 0;
}
int main() {
	try {
		funcA();
	}
	catch (std::exception& e) {
		std::cout << "Exception : " << e.what();
	}
}
/* (실습 1-1) 분석결과 :
	1. try문의 funcA()를 실행하여, r('A')객체가 생성되었다.
	2. funcB()를 실행하고, r('B')객체가 생성되었다.
	3. "Executed in B" 출력 후, funcB()가 종료되면서 r('B')객체가 소멸되어 소멸자가 호출된다.
	4. funcA()의 funcB()호출 다음줄(22줄)로 넘어와서 "Executed in A"를 출력한다.
	5. funcA()가 종료되면서 r('A')객체가 소멸되고 소멸자가 호출된다.
*/

/* (실습 1-2) 분석결과 :
	1. try문의 funcA()를 실행하여, r('A')객체가 생성되었다.
	2. funcB()를 실행하고, r('B')객체가 생성되었다.
	3. runtime_error를 throw해 바로 funcB()를 빠져나와 r('B')객체 소멸자가 호출된다.
	4. funcA()의 나머지 코드를 실행하지 않고, 종료되면서 r('A')객체 소멸자가 호출된다.
	5. catch문의 코드를 실행시킨다.
*/