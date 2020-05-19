#pragma once
#include "Line.h"

template<class T>
class Circle : public Line<T>
{
	using Line<T>::GetLength;
public:
	Circle() : Line<T>() {}
	Circle(int n) : Line<T>(n) {}
	Circle(const Circle& c) : Line<T>(c) {}
	virtual ~Circle() {};

	double GetRadius() const;
	double GetArea() const;

	ostream& print(ostream& os);
};

#include "Circle_i.h"