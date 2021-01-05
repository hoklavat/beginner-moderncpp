//06-Exception
//report errors found at run time.

#include <iostream>

class C{
public:
	C(int x){
		if(x > 10) throw std::out_of_range{"Exception: Large Number."};
	}
};

int main(){
	try{
		C c{15};
	}
	catch(std::out_of_range){
		std::cout << "Exception occured.\n";
	}
}