//18-Void

#include <iostream>

template<typename T>
int* f(T *a){
	void *p{a}; //increment, dereference, assignment without casting is prevented for void pointer.
	int *b{static_cast<int*>(p)}; //address transfer.
	return b;
}

int main(){
	int *a = new int{123};
	std::cout << a << std::endl;
	std::cout << f(a) << std::endl;
}