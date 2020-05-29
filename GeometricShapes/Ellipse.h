#pragma once
#include "Triangle.h"

template<class T>
class Ellipse : public Triangle<T>
{
public:
	Ellipse() : Triangle<T>() {}
	Ellipse(int n) : Triangle<T>(n) {}
	Ellipse(int n, const vector<T>& list) : Triangle<T>(n, list) {}
	Ellipse(const Ellipse& e) : Triangle<T>(e) {}
	virtual ~Ellipse() {};

	double GetAxisA() const;
	double GetAxisB() const;
	double GetPerimeter() const;
	double GetArea() const;

	ostream& print(ostream& os);
};

#include "Ellipse_imp.h"