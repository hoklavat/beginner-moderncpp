//52-UserDefinedLiteral

#include <iostream>
	
class A{
public:
	A(int x): a{x}{}
	int a;
};

A operator ""_S(long double x){
	return A{x*x}; //square.
}

int main(){
	A a{12.0_S};
	std::cout << a.a << std::endl;
}