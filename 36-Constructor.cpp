//36-Constructor

#include <iostream>

class C{
public:	
	/*explicit*/ C(int a = 0): a{a}{ //default constructor. no arg or initialized args.
		std::cout << "default constructor." << std::endl;
	}
	
	int a;
};

int main(){
	C c1(1);
	C c2{2};
	C c3 = 3; //implicit initialization is not possible if constructor is declared as explicit.
	C c4 = C(4);
	C c5 = (C)5;	
	std::cout << c1.a << ", " << c2.a << ", " << c3.a << ", " << c4.a << ", " << c5.a << std::endl;
	std::cout << std::endl;
	
	C c6[3]{1, 2, 3};
	C c7[3] = {C(1), C(2), C(3)};	
	std::cout << c6[2].a << ", " << c7[2].a << std::endl;
}