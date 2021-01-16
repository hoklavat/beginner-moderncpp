//31-NamedCast

#include <iostream>

int main(){
	//reinterpret_cast. conversion between unrelated types.
	char c1 = 'a';
	std::cout << (int)&c1 << "-" << c1 << std::endl;
	int *i = reinterpret_cast<int*>(&c1); //float and int are same sized. 4-bytes.
	std::cout << (int)i << "-" << *i << std::endl;
	char* c2 = reinterpret_cast<char*>(i);
	std::cout << (int)c2 << "-" << *c2 << std::endl;
}