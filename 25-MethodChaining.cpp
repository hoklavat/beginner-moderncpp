//25-MethodChaining

#include <iostream>

class A{
public:
	void f(){
		std::cout << "Method A.f" << std::endl;
	}
};

class B{
public:
	A& f(){
		A a;
		std::cout << "Method B.f" << std::endl;
		return a;
	}
};

int main(){
	B b;
	b.f().f();
}