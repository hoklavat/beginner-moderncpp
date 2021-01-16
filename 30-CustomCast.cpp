//30-CustomCast

#include <iostream>

template<class Target, class Source>
Target narrow_cast(Source v){
	auto r = static_cast<Target>(v);
	if(static_cast<Source>(r) != v)
		throw std::runtime_error("narrow_cast failed.");
	return r;
}

int main(){
	auto c1 = narrow_cast<char>(128); //maximum value for signed char is 127.
}