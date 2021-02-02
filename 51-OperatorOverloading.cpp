//51-OperatorOverloading

#include <iostream>

class A{
private:
	int a;
	int b;
public:
	A(int x, int y): a{x}, b{y}{}
	A(): A{0, 0}{}
	
	//Unary.
	A operator-(); //negation. (-x)
	A operator++(); //prefix increment. (++x)
	A& operator++(int); //suffix increment. (x++)
	A operator--(); //prefix decrement. (--x)
	A& operator--(int); //suffix decrement. (x--)
	A operator!(); //not (!x)
	
	//Binary.
	A operator+(const A&); //add. (x+y)
	A operator-(const A&); //subtract. (x-y)
	A operator*(const A&); //multiply. (x*y)
	A operator/(const A&); //divide. (x/y)
	
	//modulo. (%)
	//xor. (^)
	//and. (&)
	//or. (|)
	//complement. (~)	
	//comma. (,)
	//assignment. (=)
	//less than. (<)
	//greater than. (>)
	//less than or equal. (<=)
	//greater than or equal. (>=)	
	//left shift. (<<)
	//right shift. (>>)
	//equals. (==)
	//not equals. (!=)
	//conditional and. (&&)
	//conditional or. (||)
	//self addition. (+=)
	//self subtraction. (-=)
	//self division. (/=)
	//self modulo. (%=)
	//self xor. (^=)
	//self and. (&=)
	//self or. (|=)
	//self multiply. (*=)
	//self left shift. (<<=)
	//self right shift. (>>=)
	//subscript. ([])
	//function call. (())
	//pointer value access. (->)
	//pointer pointer value access. (->*)
	//allocation. (new)
	//array allocation. (new [])
	//deallocation. (delete)
	//array deallocation. (delete [])
	
	
	void show(){
		std::cout << "a=" << a << ", b=" << b << std::endl;
	}
};

A A::operator-(){
	a = -a;
	b = -b;
}

A A::operator++(){
	a = a+1;
	b = b+1;
}

A& A::operator++(int){
	a = a+1;
	b = b+1;
}

A A::operator--(){
	a = a-1;
	b = b-1;
}

A& A::operator--(int){
	a = a-1;
	b = b-1;
}

A A::operator!(){
	a = (a!=0)?0:1;
	b = (b!=0)?0:1;
}

A A::operator+(const A& x){
	A temp{this->a + x.a, this->b + x.b};	
	return temp;
}

A A::operator-(const A& x){
	A temp{this->a - x.a, this->b - x.b};	
	return temp;
}

A A::operator*(const A& x){
	A temp{this->a * x.a, this->b * x.b};	
	return temp;
}

A A::operator/(const A& x){
	A temp{this->a / x.a, this->b / x.b};	
	return temp;
}

int main(){
	A a1{1, 2};	
	a1.show();
	
	-a1;
	a1.show();
	
	++a1;
	a1.show();
	
	a1++;
	a1.show();
	
	--a1;
	a1.show();
	
	a1--;
	a1.show();
	
	!a1;
	a1.show();
	
	!a1;
	a1.show();
	
	A a2 = a1+A{2, 3};
	a2.show();
	
	a2 = a1-A{2, 3};
	a2.show();
	
	a2 = a1*A{10, 10};
	a2.show();
	
	a2 = a2/A{2, 2};
	a2.show();
}