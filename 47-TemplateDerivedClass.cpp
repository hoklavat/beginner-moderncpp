//47-TemplateDerivedClass

#include <iostream>

void g(){std::cout << "Hello from global." << std::endl;}

template<typename T>
class A{
public:
	class X{}; //nested type.
	typedef int Y; //nested type.
	void g(){std::cout << "Hello from A." << std::endl;}
};

template<typename T>
class B: public A<T>{
public:
	void f(){
		typename A<T>::X x; //ERROR: X x; A<T>::X x;
		typename A<T>::Y y;
		g(); //g of Global.
		A<T>::g(); //g of A.
	}
};

int main(){
	B<int> b;
	b.f();	
}