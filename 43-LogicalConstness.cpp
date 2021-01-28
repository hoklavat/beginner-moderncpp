//43-LogicalConstness

#include <iostream>

//Method 1
class A{
private:
	int x;
	mutable int y;
public:
	void f() const{
		//x = 1; //error. impossible to change member state in constant function unless mutable keyword is used.
		y = 1;
	}
};

//Method 2
struct S{
	int x;
};

class B{
private:
	S* s;
public:
	void f() const{
		s->x = 1; //const does not apply (transitively) to objects accessed through pointers or references.
	}
};

int main(){
	A a;
	a.f();
	
	B b;
	b.f();
}