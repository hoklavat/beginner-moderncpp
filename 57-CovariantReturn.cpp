//57-CovariantReturn
//Return Type Relaxation.

#include <iostream>

class A{
public:
	A(){};
	A(int x){
		std::cout << "base class constructor." << x << std::endl;
	}
	
	virtual A* make(int x){
		return new A{x};
	}
};

class B: public A{
public:
	B(int x){
		std::cout << "derived class constructor." << x << std::endl;
	}
	
	B* make(int x) override{ //return type is derived type, not base.
		return new B{x};
	}
};

int main(){
	B b1{1};
	B *b2{b1.make(2)};
}