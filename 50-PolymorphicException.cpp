//50-PolymorphicException

#include <iostream>

class A{
public:
	virtual void raise(); 
};

void A::raise(){
	std::cout << "Class A raised exception." << std::endl;
	throw *this;
}

class B: public A{
public:
	virtual void raise();
};

void B::raise(){
	std::cout << "Class B raised exception." << std::endl;
	throw *this;
}

void f(A& e){
	e.raise();
}

int main(){
	B b;
	
	try{
		f(b);
	}
	catch(B& e){
		std::cout << "B type exception is catched." << std::endl;
	}
	catch(...){
		std::cout << "Other type exception is catched." << std::endl;
	}
}