//10-Copy

#include <iostream>

class A{
private:
	int *data;
	int size;
	
public:
	A(int s): size{s}{
		data = new int[s];
	}
	
	//Copy Constructor.	
	//A(const A&) = delete; //prohibit copying.
	A(const A& a): data{new int[a.size]}, size{a.size}{
		for(int i = 0; i < a.size; i++)
			data[i] = a.data[i];
	}
	
	//Copy Assignment.
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
	
	A b(a);
	b.print();
	
	std::cout << std::endl;
	
}