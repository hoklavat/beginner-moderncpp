//69-TypeSelection

#include <iostream>

struct A{
	constexpr int operator()(int i){return i*2;}
};

struct B{
	constexpr int operator()(int i){return i*3;}
};

template<bool B, typename X, typename Y>
using Conditional = typename std::conditional<B, X, Y>::type;

int main(){
	std::conditional<(1==2), int, double>::type t; //select double type.
	std::cout << typeid(t).name() << std::endl;	
	
	auto a = Conditional<(1==2), A, B>{}(10); //select B type.
	std::cout << a << std::endl;
}