//53-RangedFor

#include <iostream>
#include <cstring>
#include <algorithm>

class A{
private:
	char* s;
	int size;
public:
	A(const char* t){
		size = strlen(t);
		s = new char(size);
		strcpy(s, t);
	}
	
	void print(){
		std::cout << s << std::endl;
	}
	
	friend char* begin(A& x);
	friend char* end(A& x);
};

char* begin(A& x){
	return x.s;
}
	
char* end(A& x){
	return x.s+x.size;
}

int main(){
	A a{"Hello World!"};	
	a.print();
	
	for(auto c: a)
		std::cout << c;
	std::cout << std::endl;
	
	std::for_each(begin(a), end(a), [](char c){std::cout << c;});
	std::cout << std::endl;
}