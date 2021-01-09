//18-Void

#include <iostream>

template<typename T>
int* f(T *a){
	void *p{a}; //increment, decrement, dereference, assignment without casting is prohibited with void pointer.
	int *b{static_cast<int*>(p)};
	return b;
}

int main(){
	int *a = new int{123};
	std::cout << a << std::endl;
	std::cout << f(a) << std::endl;
}