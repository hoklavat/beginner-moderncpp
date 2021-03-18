//63-DefaultFunctionTemplateArguments

#include <iostream>
#include <iomanip>

template<typename Target=std::string, typename Source=std::string>
Target to(Source arg){
	std::stringstream interpreter;
	Target result;
	
	if(!(interpreter<<arg) || !(interpreter>>result) || !(interpreter>>std::ws).eof())
		throw std::runtime_error{"to<>() failed"};
	
	return result;
}

int main(){
	auto x1 = to<std::string, double>(1.2);
	auto x2 = to<std::string>(1.2);
	auto x3 = to<>(1.2);
	auto x4 = to(1.2);
	
	std::cout << x1 << ", " << x2 << ", " << x3 << ", " << x4 << std::endl;
}