//22-ConstCorrectness

#include <iostream>

void f(const int* a){
	//*a = 1; //read-only.
}

class C{
private:
	int a;
public:
	void f() const{
		//a = 1; //read-only.
	}
};

int main(){
	int a = 1;
	
	const int* x{&a}; //int const*.
	//*x = 1; //non-constant pointer to constant object. object is read-only.
	int* x2{&a};
	*x2 = 2; //legal.
	
	int* const y{&a};
	*y = 1; //constant pointer to non-constant object. pointer is read-only.
	
	const int* const z{&a};
	//*z = 1; //constant pointer to constant object. object and pointer are read-only.
}