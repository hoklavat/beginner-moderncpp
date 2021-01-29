//49-ExplicitDestructor

#include <iostream>

class A{
public:
	A();
	//~A(); //implicit destructor.
	void destroy();
private:
	~A(); //explicit destructor. won't be invoked automatically 
};

A::A(){
	std::cout << "constructor." << std::endl;
}

A::~A(){
	std::cout << "destructor." << std::endl;
}

void A::destroy(){
	this->~A();
}

int main(){
	//A a; //error.
	A* a = new A();
	
	//delete a; //error.
	a->destroy();	
}