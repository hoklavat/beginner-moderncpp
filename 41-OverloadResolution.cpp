//41-OverloadResolution

#include <iostream>

class A{
public:
	int f(int a){std::cout << "Integer f(): " << a+1 << std::endl; return(a+1);}
};

class B: A{
public:
	//using A::f; //make every f in A available in B.
	double f(double a){std::cout << "Double f(): " << a+2.5 << std::endl; return(a+1.5);}
};

int main(){
	B b;
	b.f(3.2); //input type double. call f(double).
	b.f(3); //input type integer. calls f(double), not f(int). using A::f declaration is disabled.	
}