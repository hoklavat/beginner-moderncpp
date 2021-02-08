//54-Override

#include <iostream>

class A{
public:
	virtual void print(){
		std::cout << "class A print function." << std::endl;
	}
};

class B: public A{
public:
	void print() override{ //also virtual. no need to use virtual again.
		std::cout << "class B print function." << std::endl;
		A::print(); //explicit qualification.
	}
};

int main(){
	B b;
	b.print();
	
	A& a = b;
	a.print();
}