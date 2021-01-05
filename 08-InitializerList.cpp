//08-InitializerList

#include <iostream>

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
}