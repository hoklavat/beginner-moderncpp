//44-StaticMember

#include <iostream>

class A{
private:
	static int x; //static property.
public:
	A(){x++;}	
	int f(){return x;}
	static int g(){return x;} //static method.
};
int A::x = 0; //static member initialization.

int main(){
	A *a[10];
	
	for(int i = 0; i < 10; i++){
		a[i] = new A();		
	}
	
	std::cout << "Number of objects: " << a[0]->f() << std::endl;
	std::cout << "Number of objects: " << A::g() << std::endl;
}