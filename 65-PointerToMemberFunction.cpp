//65-PointerToMemberFunction

#include <iostream>

class A{
public:
	int f(int x, int y){std::cout << "f is called." << std::endl;}
	int g(int x, int y){std::cout << "g is called." << std::endl;}	
};

typedef int (A::*pmf)(int x, int y);

int main(){
	A a1;
	pmf p1 = &A::f;
	(a1.*p1)(1,2); //std::invoke(p1, a1, 1, 2);

	A *a2 = new A();
	pmf p2 = &A::g;
	(a2->*p2)(1,2);
}
