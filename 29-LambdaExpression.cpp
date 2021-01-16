//29-LambdaExpression

#include <iostream>
#include <vector>
#include <algorithm>

void printModulo(const std::vector<int>& v, std::ostream& os, int m){
	//auto modulo = [&os, m](int x){if(x%m==0) os << x << " ";};
	for_each(v.begin(), v.end(), [&os, m](int x){if(x%m==0) os << x << " ";}); //modulo can be used instead of expression.
}

int main(){
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
	printModulo(v, std::cout, 3); //print integers that can be divided by 3.	
}