//14-Alignment

#include <iostream>

struct S{
	char x;
	int y;
	double z;
};

int main(){
	alignas(int) S s;
	
	std::cout << "char: " << alignof(char) << std::endl;
	std::cout << "int: " << alignof(int) << std::endl;
	std::cout << "double: " << alignof(double) << std::endl;
	std::cout << "S: " << alignof(S) << std::endl;	
	std::cout << "s: " << alignof(s) << std::endl;
}