//27-DeskCalculator
//Example program presented in 10th Chapter of book C++ Programming Language written by Bjarne Stroustrup.
//Performs four arithmetic operations and variable definition.
//Main Parts; parser, input function, symbol table and driver.
//Parser: syntactic analysis. recursive descent. expr, term, prim.
//Input Function: input handling, lexical analysis.
//Symbol Table: permanent information.
//Driver: initialization, output, error handling.

#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

double expr(bool get);
double term(bool get);
double prim(bool get);

int no_of_errors;
double error(const string& s){
	no_of_errors++;
	cerr << "error: " << s << "\n";
	return 1;
}

enum class Kind: char{name, number, end, plus='+', minus='-', mul='*', div='/', print=';', assign='=', lp='(', rp=')'};

struct Token{
	Kind kind;
	string string_value;
	double number_value;
};

class Token_stream{
public:
	Token_stream(istream& s): ip{&s}, owns{false}{}
	Token_stream(istream* p): ip{p}, owns{true}{}
	~Token_stream(){close();}
	Token get(); //read and return next token.
	const Token& current(){return ct;}//most recently read token.
	void set_input(istream& s){close(); ip = &s; owns=false;}
	void set_input(istream* p){close(); ip = p; owns = true;}
private:
	void close(){if(owns) delete ip;}
	istream* ip; //pointer to input stream
	bool owns; //does Token_stream own the istream?
	Token ct{Kind::end}; //current token
};

Token Token_stream::get(){
	char ch = 0;
	*ip >> ch;
	
	switch (ch){
		case 0:
			return ct={Kind::end}; //assign and return
		case ';': case '*': case '/': case '+': case '-': case '(': case ')': case '=':
			return ct={static_cast<Kind>(ch)};
		case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
			ip->putback(ch); //put the first digit (or .) back into the input stream
			*ip >> ct.number_value; //read number into ct
			ct.kind = Kind::number;
			return ct;
		default: //name, name =, or error
			if(isalpha(ch)){
				ip->putback(ch); //put the first character back into the input stream
				*ip >> ct.string_value; // read string into ct
				ct.kind = Kind::name;
				return ct;
			}
		error("bad token");
		return ct={Kind::print};
	}
}

Token_stream ts{cin}; //use input from cin
map<string, double> table;

double prim(bool get){
	if(get) ts.get();
	switch(ts.current().kind){
		case Kind::number: //floating-point constant
		{ 
			double v = ts.current().number_value;
			ts.get();
			return v;
		}
		case Kind::name:
		{ 
			double& v = table[ts.current().string_value]; // find the corresponding
			if(ts.get().kind == Kind::assign) v = expr(true); // ’=’ seen: assignment
			return v;
		}
		case Kind::minus: // unary minus
			return -prim(true);
		case Kind::lp:
		{ 
			auto e = expr(true);
			if(ts.current().kind != Kind::rp) return error("')' expected");
			ts.get(); //eat ’)’
			return e;
		}
		default:
			return error("primary expected");
	}
}

double term(bool get){ //multiply and divide
	double left = prim(get);
	for(;;){
		switch(ts.current().kind){
			case Kind::mul:
				left *= prim(true);
				break;
			case Kind::div:
				if (auto d = prim(true)){
					left /= d;
					break;
				}
				return error("divide by 0");
			default:
				return left;
		}
	}
}

double expr(bool get){ //add and subtract.
	double left = term(get);
	for(;;){
		switch(ts.current().kind){
			case Kind::plus:
				left += term(true);
				break;
			case Kind::minus:
				left -= term(true);
				break;
			default:
				return left;
			}
	}
}

void calculate(){
	for (;;){
		ts.get();
		if(ts.current().kind == Kind::end) break;
		if(ts.current().kind == Kind::print) continue;
		cout << expr(false) << "\n";
	}
}

int main(){
	table["pi"] = 3.1415926535897932385; // inser t predefined names
	table["e"] = 2.7182818284590452354;
	calculate();
	return no_of_errors;
}