//38-ProtectedAccess
//derived class can access to base class private member by protected method of base class.

#include <iostream>

class A{
private:
	int a;
protected:
	void set(int n){a=n;};
	int get(){return a;};
public:
	A() = delete;
	A(int n): a{n}{}
};

class B: public A{
public:
	B(int n): A(n){}
	void print(){std::cout << get() << std::endl;}	
	void change(int n){set(n);}
};

int main(){
	B b{15};
	b.print();
	b.change(20);
	b.print();
}