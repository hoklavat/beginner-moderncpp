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

template<class T, int N>
void f(T (&c)[N]){
	for(int i = 0; i < N; i++)
		std::cout << c[i].data[0] << " ";
	std::cout << std::endl;
}

int main(){
	C c{1, 2, 3};
	std::cout << c.data[0] << std::endl;
	
	const std::initializer_list<int> l{0, 1, 2};
	std::vector<int> v(l);
	for(auto n: l)
		std::cout << n << ":" << v[n] << " ";
	std::cout << std::endl;
	
	C a[3] = {
		{1, 2, 3, 1, 3},
		{4, 5, 6},
		{7, 8, 9, 10}
	};
	
	f(a);
}