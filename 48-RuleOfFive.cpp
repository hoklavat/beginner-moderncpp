//48-RuleOfFive

#include <iostream>

class A{
public:
	A(); //default constructor.
	//A() = default; //use compiler generated constructor.
	//A() = delete; //no default constructor.
	A(int); //user-defined constructor.
	~A(); //destructor.
	A(const A&); //copy constructor.
	A(A&&); //move constructor.
	A& operator=(const A&); //copy assignment.
	A& operator=(A&&); //move assignment.
	
	int *a;
};

A::A(): A{0}{
	std::cout << "default constructor." << std::endl;
}

A::A(int x): a{new int{x}}{
	std::cout << "user defined constructor." << std::endl;
}

A::~A(){	
	std::cout << "destructor." << std::endl;
	delete a;
}

A::A(const A& x): a{x.a}{
	std::cout << "copy constructor." << std::endl;
}

A::A(A&& x): a{x.a}{
	std::cout << "move constructor." << std::endl;
	delete x.a;
}

A& A::operator=(const A& x){
	A t{*x.a};
	std::cout << "copy assignment." << std::endl;
	return t;
}

A& A::operator=(A&& x){
	A t{*x.a};
	std::cout << "move assignment." << std::endl;
	return t;
}

int main(){
	A a;	
	std::cout << std::endl;
	
	A b{1};
	std::cout << std::endl;
	
	A c{a};
	std::cout << std::endl;
	
	A d{};
	std::cout << std::endl;
	
	a = b;
	std::cout << std::endl;
	
	d = std::move(a); //stl function that returns rvalue reference for given argument.
	std::cout << std::endl;
	
	A e{std::move(a)};
	std::cout << std::endl;
	
}