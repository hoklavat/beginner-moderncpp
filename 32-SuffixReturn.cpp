//32-SuffixReturn
//useful when argument types are changeable.

#include <iostream>

template<typename T1, typename T2>
auto mul(T1 a, T2 b) -> decltype(a*b){
	return a*b;
}

int main(){
	auto a = mul(2, 2.4);
	std::cout << a << std::endl;
	std::cout << typeid(a).name() << std::endl;
}