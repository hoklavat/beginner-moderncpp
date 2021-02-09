//58-PointerToMember

#include <iostream>

class A{
public:
	void f(int x){
		std::cout << "A::f is called. " << x << std::endl;
	}
	
	char x;
};

int main(){
	using pf = void (A::*)(int);
	pf sf = &A::f; //pointer to member function.
	
	using pd = char (A::*);
	pd sd = &A::x; //pointer to member data.
	
	A *a = new A();
	a->f(1);
	(a->*sf)(2);
	
	a->*sd = 'a';
	std::cout << a->*sd << std::endl;
}