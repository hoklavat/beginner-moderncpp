//64-TemplateSpecialization

#include <iostream>

template<typename T>
class A{
public:	
	A(){std::cout << "Primary specialization." << std::endl;}
};

template<typename T>
class A<T*>{
public:
	A(){std::cout << "Pointer specialization." << std::endl;}
};

template<>
class A<void*>{
public:
	A(){std::cout << "Void specialization." << std::endl;}
};

int main(){
	A<int> a1;
	A<int*> a2;
	A<void*> a3;
}
