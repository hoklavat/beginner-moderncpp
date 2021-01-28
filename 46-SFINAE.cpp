//46-SFINAE
//Substitution Failure Is Not An Error.
//template specialized overloaded function signatures should match.

#include <iostream>
#include <typeinfo>

template<typename T>
void f(T* x){ //pointer.
	std::cout << "template function with type: " << typeid(T).name() << std::endl;
}

void f(int x){ //non-pointer.
	std::cout << "non-template function with integer argument." << std::endl;
}

void f(double x){ //non-pointer.
	std::cout << "non-template function with double argument." << std::endl;
}

int main(){	
	f(15);
	f(3.14);
	
	double *x = new double(19.2);
	f("Boris");
	f(x);
}