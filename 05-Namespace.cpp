//05-Namespace
//used to organize components.

namespace N{
	void f(){} //N namespace.
};

void f(){} //global scope.

int main(){
	//using namespace N; //error. conflict.
	N::f();
	f();
}