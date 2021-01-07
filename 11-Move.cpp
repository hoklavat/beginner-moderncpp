//11-Move

#include <iostream>

class A{
private:
	int *data;
	int size;
	
public:
	A(int s): size{s}{
		data = new int[s];
	}
	
	~A(){};
	
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
	}
};

int main(){
	A a(10);
	a.fill(10);
	
	A b(10);
	b = std::move(a);
	b.print();
}