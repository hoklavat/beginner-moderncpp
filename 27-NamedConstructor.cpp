//27-NamedConstructor
//constructors are private/protected. objects are constructed via create methods using new.

#include <iostream>

class C{
private:
	int n;
	C(): n{0}{std::cout << "no arg constructor." << std::endl;}
	C(int n): n{n}{std::cout << "one arg constructor." << std::endl;}
public:
	static C *create(){return new C();}
	static C *create(int n){return new C(n);}
};

int main(){
	C *c = C::create(10);
}