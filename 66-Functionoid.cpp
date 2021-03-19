//66-Functionoid

#include <iostream>

class F{
public:
	virtual int Do(int x) = 0;
};

typedef F* pf;

class F1: public F{
public:
	F1(int x): a{x}{}
	virtual int Do(int x){std::cout << "F1 is called. " << x << std::endl;}
private:
	int a;	
};

class F2: public F{
public:
	F2(int x, int y): a{x}, b{y}{}
	virtual int Do(int x){std::cout << "F2 is called. " << x << std::endl;}
private:
	int a;
	int b;
};

class F3: public F{
public:
	F3(double x): a{x}{}
	virtual int Do(int x){std::cout << "F3 is called. " << x << std::endl;}
private:
	double a;	
};

int main(){
	pf p1 = new F1(1);
	pf p2 = new F2(1, 2);
	pf p3 = new F3(1.2);
	
	p1->Do(1);
	p2->Do(2);
	p3->Do(3);
}