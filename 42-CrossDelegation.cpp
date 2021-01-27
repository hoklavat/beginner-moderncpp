//42-CrossDelegation

#include <iostream>

class O{
public:
	virtual void f() = 0;
	virtual void g() = 0;
};

class A: public virtual O{
public:
	virtual void f(){
		g();
	}
};

class B: public virtual O{
public:
	virtual void g(){
		std::cout << "B::g()" << std::endl;
	}
};

class C: public A, public B{
public:
	
};

int main(){
	C *p1 = new C();
	A *p2 = p1;
	O *p3 = p1;
	p1->f();
	p2->f();
	p3->f();
}