//13-StandartIO

#include <iostream>
#include <limits>

int main(){
	int i = 0;
	
	//GOOD FORM. invalid inputs cause break or gives information.
	while((std::cout << "Enter number between 1 and 10: ") && (!(std::cin >> i) || i < 1 || i > 10)){
		std::cout << "Try again." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}	
	
	/*
	//BAD FORM
	while(i != -1){
		std::cin >> i; //non integer inputs cause infinite loop.
		std::cout << "You've entered " << i << std::endl;
	}
	*/
	
}