//12-ExternalC
//calling c function from c++ source.

#include "g.h"

extern "C" {
	void f(); //declaration of c function inside c++ source.
}

void f(){
	printf("Good Bye!\n"); //stdio already included in g header.
}

int main(){
	g(); //calling c function from c header file.
	f();
};