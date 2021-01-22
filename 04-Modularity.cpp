//04-Modularity
//declaration and implementation are seperated.

//class.h
class C{
	int x;
	void f(int);
};

//class.cpp
//#include "class.h"
void C::f(int y){
	x = y;
}

//main.cpp
//#include "class.h"
int main(){}