//40-Versioning

#include <iostream>

namespace N{
	
	inline namespace V_3{
		void f(){std::cout << "Version 3" << std::endl;}
	}

	namespace V_2{
		void f(){std::cout << "Version 2" << std::endl;}
	}

	namespace V_1{
		void f(){std::cout << "Version 1" << std::endl;}
	}
	
}

int main(){
	using namespace N;
	
	f(); //default version is inlined one.
	V_2::f();
	V_1::f();
	
}