//16-TypeDeduction

#include <iostream>

template<typename T>
auto f(T a) -> decltype(T{}){
	return typeid(a).name();
}

int main(){
	int a{1};
	auto b{a}; //b is type of a.
	decltype(f("Hello")) c{"Bye"}; //type of c is determined by expression.
	
	std::cout << b << std::endl;
	std::cout << f("Hello") << std::endl;
	std::cout << c << std::endl;
}