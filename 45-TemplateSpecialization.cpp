//45-TemplateSpecialization

#include <iostream>
#include <typeinfo>

template<typename T>
void f(T x){
	std::cout << "neither integer nor string. " << typeid(T).name() << "-" << x << std::endl;
}

template<>
void f<int>(int x){
	std::cout << "integer version. " << x << std::endl;
}

template<>
void f<std::string>(std::string x){
	std::cout << "string version. " << x << std::endl;
}

int main(){
	std::string s = "Haydar";
	f(10);
	f(s);
	f("Boris");
	f(13.2);
}