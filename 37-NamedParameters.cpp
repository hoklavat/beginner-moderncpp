//37-NamedParameters
//pass parameters using class methods.

#include <iostream>

class C{
private:
	int a1;
	int a2;
	int a3;
	friend class D;
public:
	C(int x): a1{x}, a2{0}, a3{0}{}	
	C& A1(){a1=1;}
	C& A2(){a2=2;}	
	C& A3(){a3=3;}
};

class D{
public:
	D(const C& params){
		std::cout << params.a1 << std::endl;
		std::cout << params.a2 << std::endl;
		std::cout << params.a3 << std::endl;
	}
};

int main(){
	D d = C(10).A3().A1().A2(); //parameter order is unimportant.
}