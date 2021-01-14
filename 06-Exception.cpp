//06-Exception
//report errors found at run time.

#include <iostream>

class C{
public:
	C(int x){
		if(x > 10) throw std::out_of_range{"Exception: Large Number."};
	}
};

class Error: public std::exception{
public:
	Error(): exception(){}
};

int main(){
	
	try{
		//C c{15};
		if(1 == 1) throw Error();
	}
	catch(std::out_of_range){
		std::cout << "Exception occured." << std::endl;
	}
	catch(Error){
		std::cout << "Error occured." << std::endl;
	}
	
}