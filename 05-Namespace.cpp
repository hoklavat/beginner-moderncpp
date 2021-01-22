//05-Namespace
//used to organize components.

namespace N{
	void f(){}
	void g(){}
};

namespace Namespace_Long{
	void f(){}
};

void f(){} //global.

int main(){
	//using namespace N; //error. there are conflicts for f.	
	using N::g;
	
	N::f(); //N::f()
	g(); //N::g()
	
	f(); //::f(). global.
	
	namespace n = Namespace_Long; //namespace alias.
	n::f(); //Namespace_Long::f();
}