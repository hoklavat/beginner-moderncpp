//68-TypePredicate

#include <iostream>

template<typename T>
constexpr bool isBig(){
	return sizeof(T) > 2;
}

template<typename T>
void Check(){
	if(isBig<T>()){std::cout << "It is a big type." << std::endl;}
	else{std::cout << "It is not a big type." << std::endl;}
}

int main(){
	Check<char>();
	Check<int>();
}