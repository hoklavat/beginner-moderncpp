//06-Exception
//error checking at run-time.

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
	catch(std::out_of_range){ //built-in exception class.
		std::cout << "Exception occured." << std::endl;
	}
	catch(Error){ //user-defined exception class.
		std::cout << "Error occured." << std::endl;
	}
	
}