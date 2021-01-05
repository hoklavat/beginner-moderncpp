//07-StaticAssertion
//compile time error checking.

#include <iostream>

int main(){
	const int x = 15;
	static_assert(x<10, "integer is too large."); //error at compile time.
}