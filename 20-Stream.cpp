//20-Stream

#include <iostream>

class A{
private:
	int a;
	std::string b;
	
public:
	A(): a{0}, b{""}{}
	
	set(int a, std::string b){
		this->a = a; 
		this->b = b;
	}
	
	print(){
		std::cout << "a=" << a << ", b=" << b << std::endl;
	}
	
	friend std::istream& operator>>(std::istream &i, A &a);
	friend std::ostream& operator<<(std::ostream &o, A &a);
};

std::istream& operator>>(std::istream &i, A &a){
	return i >> a.b;
}

std::ostream& operator<<(std::ostream &o, A &a){
	return o << a.b;
}

int main(){
	A a;
	a.set(1, "Jack");
	a.print();
	
	std::cout << "Change name: ";
	std::cin >> a;
	std::cout << "New Name: " << a << std::endl;;
}