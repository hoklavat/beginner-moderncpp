//55-UsingDirective

#include <iostream>

class A{
public:
	void f(int x){
		std::cout << "integer. " << x << std::endl;
	}
};

class B: public A{
public:
	void f(double x){
		std::cout << "double. " << x << std::endl;
	}
};

class C: public B{
public:
	using A::f;
	using B::f;
	void f(char x){
		std::cout << "char. " << x << std::endl;
	}
};

int main(){
	C c;
	c.f(1);
	c.f(1.2);
	c.f('a');
}