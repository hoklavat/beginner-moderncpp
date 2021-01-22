//07-StaticAssertion
//error checking at compile-time.

#include <iostream>

int main(){
	const int x = 15;
	static_assert(x < 10, "integer is too large."); //if expression is false give error at compile-time.
}