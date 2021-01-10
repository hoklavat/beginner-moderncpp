//15-Scope

#include <iostream>

//global
int x{4};

//namespace
namespace N{
	int x{3};
}

//class.
class C{
private:
	int x;
public:
	C(): x{5}{}
	int getX(){return this->x;}
};

//function.
void f(){
	int x{7};
	std::cout << "7: x = " << x << std::endl;
}

int main(){
	//local.
	int x{2};
	
	{
		//inner local.
		int x{1};
		std::cout << "1: x = " << x << std::endl;
	}
	
	std::cout << "2: x = " << x << std::endl;
	std::cout << "3: x = " << N::x << std::endl;
	std::cout << "4: x = " << ::x << std::endl;
	
	C c;
	std::cout << "5: x = " << c.getX() << std::endl;	
	
	//statement.
	std::cout << "6: x = ";
	for(x = 0; x <= 2; x++)
		std::cout << x << " ";
	std::cout << std::endl;
	
	f();
}