//67-Functor

#include <iostream>

class F1{
public:
	F1(int x): a{x}{}
	int operator()(int x){std::cout << "F1 is called. " << x << std::endl;}
private:
	int a;	
};

class F2{
public:
	F2(int x, int y): a{x}, b{y}{}
	int operator()(int x){std::cout << "F2 is called. " << x << std::endl;}
private:
	int a;
	int b;
};

class F3{
public:
	F3(double x): a{x}{}
	int operator()(int x){std::cout << "F3 is called. " << x << std::endl;}
private:
	double a;
};

template<typename F>
void Action(F f){
	f(1);
}

int main(){
	F1 f1(1);
	F2 f2(1, 2);
	F3 f3(1.2);
	
	Action(f1);
	Action(f2);
	Action(f3);
}