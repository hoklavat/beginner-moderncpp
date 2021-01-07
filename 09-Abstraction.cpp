//09-Abstraction

#include <iostream>

//Interface/Abstract Class/Super Class/Base Class.
class A{
public:
	//Pure Virtual Function.
	virtual void f() = 0;
	
	//Virtual Destructor.
	virtual ~A(){
		std::cout << "A - destructor." << std::endl;
	} 
};

//Concrete Class/Sub Class/Derived Class.
class B: public A{
public:
	B(){
		std::cout << "B - constructor." << std::endl;
	}
	
	~B(){
		std::cout << "B - destructor." << std::endl;
	}
	
	//Override.
	void f(){
		std::cout << "Hello World!" << std::endl;
	}
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