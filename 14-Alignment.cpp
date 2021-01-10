//14-Alignment

#include <iostream>

struct S{
	char x;
	int y;
	double z;
};

struct T{
	//char a; //not properly aligned. 24 bytes total.
	double x;
	int y;
	char z;
	char a; //properly aligned. 16 bytes total. order from largest to smallest.
};

int main(){
	alignas(int) S s;
	
	std::cout << "char: " << alignof(char) << "," << sizeof(char) << std::endl;
	std::cout << "int: " << alignof(int) << "," << sizeof(int) << std::endl;
	std::cout << "double: " << alignof(double) << "," << sizeof(double) <<  std::endl;
	std::cout << "S: " << alignof(S) << "," << sizeof(S) <<  std::endl;
	std::cout << "s: " << alignof(s) << "," << sizeof(s) <<  std::endl;
	std::cout << "T: " << alignof(T) << "," << sizeof(T) <<  std::endl;
}