//70-VariadicTemplate

#include <iostream>

void f(){}

template<typename T>
void g(T x){
	std::cout << x << std::endl; 
}

template<typename T, typename... Tail>
void f(T head, Tail... tail){
	g(head);
	f(tail...);
}

int main(){
	f(1, "Hello", 2.3);
}