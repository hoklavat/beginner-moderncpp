//26-MemoryAllocation

#include <iostream>
#include <memory>
#include <vector>

void f(){
	std::vector<char*> v;
	try{
		while(true){
			char *p = new char[10000]; //new(std::nothrow) char[10000]. returns nullptr rather throwing exception.
			v.push_back(p);
			p[0] = 'x';
		}
	}
	catch(std::bad_alloc){ //new throws exception if there is not enough memory.
		std::cerr << "Memory exhausted" << std::endl;
	}
}

int main(){
	
	//C Style Memory Allocation.
	void *p1 = malloc(10); //allocate 10 bytes.
	realloc(p1, 20); //allocate 20 bytes.
	free(p1); //deallocate 20 bytes.
	
	//C++ Style Memory Allocation.
	int *p2 = new int; //allocate 1 integer initialized with random number.
	if(p2 == nullptr) throw std::bad_alloc(); //not enough memory.	
	int *p3 = new int(); //allocate 1 integer initialized with 0.
	int *p4 = new int(10); //allocate 1 integer initialized with 10.
	int *p5 = new int[10]; //allocate 10 integers initialized with random numbers.
	delete p2; //doesn't deallocate automatically.
	p2 = nullptr; //deleting same location again could cause crash.
	delete p3;
	p3 = nullptr;
	delete p4;
	p4 = nullptr;
	delete[] p5;
	p5 = nullptr;
	
	//C++ Style Pointer Allocation.
	std::unique_ptr<int> p6 = std::make_unique<int>(10); //automatically deallocated at end of scope.
	std::unique_ptr<int> p7 = std::make_unique<int>(20);
	p7 = move(p6);
	if(p6 == nullptr) std::cout << "p6 is disposed. p7 is " << *p7 << std::endl;	
	
	//Container Allocation.
	std::vector<int> v; //automatically deallocated at end of scope.
	for(int i = 0; i < 10; ++i)
		v.push_back(i*10);
	
	f();
}