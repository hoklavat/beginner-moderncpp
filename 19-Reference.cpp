//19-Reference

#include <iostream>

//pass original argument rather than making copy.
void f(int &r){
	r++;
}

int main(){
	//L-Value Reference
	int a{1};
	//int &b; //error. must initialize.
	//int &b{1} //error. lvalue needed.
	int &b{a};
	int *p = &b;
	const int d{1};
	
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "*p = " << *p << std::endl;
	std::cout << "&a = " << &a << std::endl;
	std::cout << "&b = " << &a << std::endl;
	std::cout << "p = " << p << std::endl;
	
	f(a);
	std::cout << "a = " << a << std::endl;
	
	//R-Value Reference
	//int &&x{a}; //error. not rvalue.
	int &&x{static_cast<int&&>(a)}; //convert lvalue to rvalue.
	std::cout << "x = " << x << std::endl;
}