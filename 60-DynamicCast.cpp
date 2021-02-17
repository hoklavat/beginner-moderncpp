//60-DynamicCast

#include <iostream>

class A{
public:
	virtual void print(){
		std::cout << "Hello from A." << std::endl;
	}
};

class B: public A{
public:
	void print() override{
		std::cout << "Hello from B." << std::endl;
	}
};

class C: public A{
public:
	void print() override{
		std::cout << "Hello from C." << std::endl;
	}
};

//Base to Derived.
void Downcast(A* a){
	auto p = dynamic_cast<B*>(a);
	if(p){std::cout << "Downcast possible." << std::endl; p->print();}
	else{std::cout << "Downcast not possible." << std::endl;}
}

//Derived to Base.
void Upcast(B* b){
	auto p = dynamic_cast<A*>(b);
	if(p){std::cout << "Upcast possible." << std::endl; p->print();}
	else{std::cout << "Upcast not possible." << std::endl;}
}

int main(){
	B* b = new B();
	Downcast(b);
	
	C* c = new C();
	Downcast(c);
	
	Upcast(b);
}