//61-DoubleDispatch

#include <iostream>
#include <vector>

class Circle;
class Triangle;

class Shape{
public:
	virtual bool intersect(const Shape&) const = 0;
	virtual bool intersect(const Circle&) const = 0;
	virtual bool intersect(const Triangle&) const = 0;
};

class Circle: public Shape{
public:
	bool intersect(const Shape&) const override;
	virtual bool intersect(const Circle&) const override;
	virtual bool intersect(const Triangle&) const override;
};

class Triangle: public Shape{
public:
	bool intersect(const Shape&) const override;
	virtual bool intersect(const Circle&) const override;
	virtual bool intersect(const Triangle&) const override;
};

bool Circle::intersect(const Shape& s) const {return s.intersect(*this);}
bool Circle::intersect(const Circle&) const {std::cout << "intersect(circle, circle)" << std::endl; return true;}
bool Circle::intersect(const Triangle&) const {std::cout << "intersect(circle, triangle)" << std::endl; return true;}

bool Triangle::intersect(const Shape& s) const {return s.intersect(*this);}
bool Triangle::intersect(const Circle&) const {std::cout << "intersect(triangle, circle)" << std::endl; return true;}
bool Triangle::intersect(const Triangle&) const {std::cout << "intersect(triangle, triangle)" << std::endl; return true;}

void Test(Triangle& t, Circle& c){
	std::vector<std::pair<Shape*, Shape*>> vs {{&t, &t}, {&t, &c}, {&c, &t}, {&c, &c}};
	for(auto p: vs)
		p.first->intersect(*p.second);
}

int main(){
	Triangle t;
	Circle c;
	Test(t, c);
}