//59-AmbiguityResolution

#include <iostream>

class A{
public:
	void f(){
		std::cout << "Hello from A." << std::endl;
	}
};

class B{
public:
	void f(){
		std::cout << "Hello from B." << std::endl;
	}
};

class C: public A, public B{
public:
	void f(){
		A::f();
		B::f();
	}
};

int main(){
	C c;
	c.f();
}