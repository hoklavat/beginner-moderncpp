//48-RuleOfFive

#include <iostream>

class A{
public:
	A(); //default constructor.
	A(int); //user-defined constructor.
	~A(); //destructor.
	A(const A&); //copy constructor.
	A(A&&); //move constructor.
	A& operator=(const A&); //copy assignment.
	A& operator=(A&&); //move assignment.
	
	int a;
};

A::A(): a{0}{
	std::cout << "default constructor." << std::endl;
}

A::A(int x): a{x}{
	std::cout << "user defined constructor." << std::endl;
}

A::~A(){
	std::cout << "destructor." << std::endl;
}

A::A(const A& x): a{x.a}{
	std::cout << "copy constructor." << std::endl;
}

A::A(A&& x): a{x.a}{
	std::cout << "move constructor." << std::endl;
}

A& A::operator=(const A& x){
	A t{x.a};
	std::cout << "copy assignment." << std::endl;
	return t;
}

A& A::operator=(A&& x){
	A t{x.a};
	std::cout << "move assignment." << std::endl;
	return t;
}

int main(){
	A a;
	A b{1};	
	A c{a};	
	A d{};
	
	a = b;
	d = std::move(a);
}