//62-Visitors

#include <iostream>
#include <vector>

class Visitor;

class Node{
public:
	virtual void accept(Visitor&) = 0;
};

class Expression: public Node{
public:
	void accept(Visitor&) override;
};

class Statement: public Node{
public:
	void accept(Visitor&) override;
};

class Visitor{
public:
	virtual void accept(Expression&) = 0;
	virtual void accept(Statement&) = 0;
};

void Expression::accept(Visitor& v){v.accept(*this);}
void Statement::accept(Visitor& v){v.accept(*this);}

class Visitor1: public Visitor{
	void accept(Expression&){std::cout << "Visitor1 to Expression" << std::endl;}
	void accept(Statement&){std::cout << "Visitor1 to Statement" << std::endl;}
};

class Visitor2: public Visitor{
	void accept(Expression&){std::cout << "Visitor2 to Expression" << std::endl;}
	void accept(Statement&){std::cout << "Visitor2 to Statement" << std::endl;}
};

void Test(Expression& e, Statement& s){
	Visitor1 v1;
	Visitor2 v2;
	std::vector<std::pair<Node*, Visitor*>> vn {{&e, &v1}, {&s, &v1}, {&e, &v2}, {&s, &v2}};
	for(auto p: vn)
		p.first->accept(*p.second);
}

int main(){
	Expression e;
	Statement s;
	Test(e, s);
}