//09-Abstraction

#include <iostream>

//interface/abstract class/super class/base class.
class A{
public:	
	virtual void f() = 0; //pure virtual function.
	virtual ~A(){std::cout << "A - destructor." << std::endl;} //virtual destructor.
};

//concrete class/sub class/derived class.
class B: public A{
public:
	B(){std::cout << "B - constructor." << std::endl;}	
	~B(){std::cout << "B - destructor." << std::endl;}	
	void f(){std::cout << "Hello World!" << std::endl;} //override.
};

int main(){
	B b;	
	b.f();
	
	std::cout << std::endl;
	
	A *a = new B();
	a->f();
	delete a;
	
	std::cout << std::endl;
}