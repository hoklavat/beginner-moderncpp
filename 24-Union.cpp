//24-Union

#include <iostream>

union U{
private:	
public:
	char a;
	unsigned b;
	long long c; //member having maximum size 8-bytes.
	
	U(){
		std::cout << "Union is constructed." << std::endl;		
		c = 0;
	}
};

int main(){
	U u;
	u.a = 'a';
	
	std::cout << "Size of union is " << sizeof(U) << std::endl;
	std::cout << "a=" << u.a << std::endl;
	std::cout << "b=" << u.b << std::endl;
}