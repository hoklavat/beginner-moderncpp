//05-Namespace
//used to organize components.

namespace N{
	void f(){} //N namespace.
	void g(){}
};

namespace Namespace_Long{
	void f(){}
};

void f(){} //global scope.

int main(){
	//using namespace N; //error. conflict.	
	using N::g;
	
	N::f();//N::f()
	g(); //N::g()
	
	f(); //::f(). global f().
	
	namespace n = Namespace_Long;
	n::f(); //Namespace_Long::f();	
}