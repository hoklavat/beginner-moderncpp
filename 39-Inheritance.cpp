//39-Inheritance

#include <iostream>

class O{
public:
	O(){std::cout << "Interface constructor." << std::endl;}
	virtual ~O(){std::cout << "Interface destructor." << std::endl;}
	virtual O* create() const = 0;
	virtual O* clone() const = 0; //virtual copy constructor.
};

class A: public O{
public:
	A(){std::cout << "Base Class constructor." << std::endl;}
	~A(){std::cout << "Base Class destructor." << std::endl;}
	virtual void f() = 0; //pure virtual function should be implemented in derived class. otherwise it is also abstract.
	virtual void g(){std::cout << "Base Class g function." << std::endl;}
};

class B: public A{
public:
	B(){std::cout << "Derived Class constructor." << std::endl;}
	~B(){std::cout << "Derived Class destructor." << std::endl;}	
	void f(){std::cout << "Derived Class f function." << std::endl;}
	void g() override{std::cout << "Derived Class g function." << std::endl;}	
	B* clone() const{return new B(*this);}
	B* create() const{return new B();}	
	int a{};
};

int main(){
	//A a; //cannot declare A because it contains pure virtual function that makes A abstract class.
	B b;
	
	b.f();
	b.g();
	b.a = 10;
	b.A::g(); //overrided base class function is called from derived class.
	
	std::cout << std::endl;
	
	A *p = new B();
	p->f();
	p->g();
	p->A::g();
	delete p;
	
	std::cout << std::endl;
	
	O *o = new B();
	delete o;
	
	std::cout << std::endl;
	
	B *b1 = b.clone(); //calls copy constructor.
	B *b2 = b.create(); //default constructor.
	std::cout << "b1->a = " << b1->a << std::endl;
	std::cout << "b2->a = " << b2->a << std::endl;
	delete b1;
	delete b2;
	
	std::cout << std::endl;
	
}