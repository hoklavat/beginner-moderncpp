//23-BitField

#include <iostream>

struct S{
	bool a: 1;
	bool b: 1; 
	bool c: 1; 
	bool d: 1;	
};

int main(){
	S s;
	s.a = 1;
	
	std::cout << "Size of bitfield: " << sizeof(S) << std::endl;
	
	if(s.a){
		std::cout << "Bit a is set." << std::endl;
	}
	
}