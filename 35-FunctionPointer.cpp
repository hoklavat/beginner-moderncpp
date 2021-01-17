//35-FunctionPointer

#include <iostream>

int square(int a){
	return a*a;
}

int factorial(int a){
	return (a<2)?1:a*factorial(a-1);
}

using F = int(*)(int);
void run(int a, F f){
	std::cout << f(a) << std::endl;
}

int main(){
	int(*p)(int);
	
	p = square; //same as p = &square.
	std::cout << p(5) << std::endl;
	
	p = factorial;
	std::cout << p(5) << std::endl;	
	
	run(5, factorial);
}