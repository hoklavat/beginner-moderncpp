//56-InheritingConstructor

#include <iostream>

class A{
public:
	A(int x){
		std::cout << "base class constructor. " << x << std::endl;
	}
};

class B: A{
public:
	using A::A;
	B(): A{3}{
		std::cout << "derived class constructor." << std::endl;
	}
};

int main(){
	B b1{1};	
	B b2;
}