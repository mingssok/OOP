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
/* (�ǽ� 1-1) �м���� :
	1. try���� funcA()�� �����Ͽ�, r('A')��ü�� �����Ǿ���.
	2. funcB()�� �����ϰ�, r('B')��ü�� �����Ǿ���.
	3. "Executed in B" ��� ��, funcB()�� ����Ǹ鼭 r('B')��ü�� �Ҹ�Ǿ� �Ҹ��ڰ� ȣ��ȴ�.
	4. funcA()�� funcB()ȣ�� ������(22��)�� �Ѿ�ͼ� "Executed in A"�� ����Ѵ�.
	5. funcA()�� ����Ǹ鼭 r('A')��ü�� �Ҹ�ǰ� �Ҹ��ڰ� ȣ��ȴ�.
*/

/* (�ǽ� 1-2) �м���� :
	1. try���� funcA()�� �����Ͽ�, r('A')��ü�� �����Ǿ���.
	2. funcB()�� �����ϰ�, r('B')��ü�� �����Ǿ���.
	3. runtime_error�� throw�� �ٷ� funcB()�� �������� r('B')��ü �Ҹ��ڰ� ȣ��ȴ�.
	4. funcA()�� ������ �ڵ带 �������� �ʰ�, ����Ǹ鼭 r('A')��ü �Ҹ��ڰ� ȣ��ȴ�.
	5. catch���� �ڵ带 �����Ų��.
*/