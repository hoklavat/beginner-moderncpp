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
	C& A1(int x){a1=x;return *this;}
	C& A2(int x){a2=x;return *this;}
	C& A3(int x){a3=x;return *this;}
};

class D{
public:
	D(const C& params){
		std::cout << params.a1 << "," << params.a2 << "," << params.a3 << std::endl;
	}
};

int main(){
	D d = C(10).A3(2).A1(4).A2(6); //parameter order is unimportant.
}