//02-Constant
//immutability.
//const: run time constant.
//constexpr: compile time constant.

int x = 1;
const int y = x;
//constexpr int z = x; //error.

//double f(double x){return x*x;}
constexpr double f(double x){return x*x;}
constexpr int z = f(10);

//In-Class Constant.
class C{
public:
	static const int c = 1; //can be referenced by pointer outside of class. const int* p = &C::c;
};
const int C::c; //definition. otherwise not lvalue error.


int main(){}