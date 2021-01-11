//03-Enum

//plain enum.
enum COLOR{Red, Green, Blue};
int C = COLOR::Red; //Red.

//strongly typed enum.
enum class color{Red, Green, Blue}; //enum class: char{...}
//int c = color::Red; //error.
//color c = 1; //error.
color c = color::Red;

int main(){}