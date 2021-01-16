//08-InitializerList

#include <iostream>
#include <vector>

class C{
public:
	C(std::initializer_list<int> l){
		data = new int[l.size()];
		std::copy(l.begin(), l.end(), data);
	}
	
	int *data;
};

int main(){
	C c{1, 2, 3};
	std::cout << c.data[0] << std::endl;
	
	const std::initializer_list<int> l{0, 1, 2};
	std::vector<int> v(l);
	for(auto n: l)
		std::cout << n << ":" << v[n] << " ";
}