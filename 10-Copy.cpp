//10-Copy
//create copy of object in constructor.

#include <iostream>

class A{
private:
	int *data;
	int size;
	
public:
	A(int s): size{s}{
		data = new int[s];
	}	
	
	//A(const A&) = delete; //restrain copy constructor.
	
	//copy constructor.
	A(const A& a): data{new int[a.size]}, size{a.size}{
		for(int i = 0; i < a.size; i++)
			data[i] = a.data[i];
	}
	
	//copy assignment operator.
	A& operator=(const A& a){
		int *p = new int[a.size];
		for(int i = 0; i < a.size; i++)
			p[i] = a.data[i];
		delete[] data;
		data = p;
		size = a.size;
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
	a.print();
	
	std::cout << std::endl;
	
	A b(a); //create copy of a.
	b.print();
	
	std::cout << std::endl;
	
	A c(5);
	c = a; //copy assignment.
	c.print();
	
	std::cout << std::endl;
	
}