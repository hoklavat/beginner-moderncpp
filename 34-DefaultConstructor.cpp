//34-DefaultConstructor

#include <iostream>

class C{
public:
	int a;
	int b;
	
	static int def_arg; //default argument.
	C(int x = {def_arg}, int y = {}): a{x}, b{y}{} //all three possible constructors.
	
	void print(){
		std::cout << "a=" << a << ", b=" << b << std::endl;
	}
};
int C::def_arg = 5;

int main(){
	C c1;
	C c2{1};
	C c3{2, 3};
	
	c1.print();
	c2.print();
	c3.print();
	
	C::def_arg = 3;
	C c4;
	c4.print();
}