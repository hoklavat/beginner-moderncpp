//17-TypeAlias

#include <iostream>

using pCHAR = char *; //pointer to char.
using pFUNC = int(*)(double); //pointer to function inputs double, outputs int.

typedef char *pchar; //old-style pointer to variable.
typedef int(*pfunc)(double); //old-style pointer to function.

int f(double a){
	return static_cast<int>(a*a);
}

int main(){
	char a{'a'};
	pCHAR pa{&a};
	pFUNC pf{f};
	
	std::cout << *pa << std::endl;
	std::cout << pf(12.3) << std::endl;
}