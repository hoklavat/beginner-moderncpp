//33-InlineFunction

#include <iostream>

inline int factorial(int n){
	return (n<2)?1:n*factorial(n-1);
}

int main(){
	std::cout << factorial(5) << std::endl;
}