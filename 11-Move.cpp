//11-Move

#include <iostream>

class A{
private:
	int *data;
	int size;
	
public:
	A(int s): size{s}{
		data = new int[s];
		fill(1);
	}
	
	~A(){}; //destructor would prevent implicit move constructor for derived classes.
	
	//Move Constructor.
	A(A&& a): data{a.data}, size{a.size}{
		std::cout << "move constructor." << std::endl;
		a.data = nullptr;
		a.size = 0;
	}
	
	//Move Assignment.
	A& operator=(A&& a){
		std::cout << "move assignment." << std::endl;
		data = a.data;
		size = a.size;
		a.data = nullptr;
		a.size = 0;
		return *this;
	}
	
	void fill(int n){
		for(int i = 0; i < size; ++i){
			data[i] = n;
		}
	}
	
	void print(){
		for(int i = 0; i < size; ++i){
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
};

int main(){
	A a{5};
	a.fill(15);
	a.print();
	
	A b = std::move(a);
	b.print();
	a.print(); //empty.
}