#pragma once
#include "Triangle.h"

template<class T>
class Cone : public Triangle<T>
{
public:
	Cone() : Triangle<T>() {}
	Cone(int n) : Triangle<T>(n)
	{
		if (n < 3)
			throw "Oi";
	}
	Cone(const Cone& e) : Triangle<T>(e) {}
	virtual ~Cone() {};

	double GetRadius() const;
	double GetHeight() const;
	double GetVolume() const;
	double GetArea() const;

	ostream& print(ostream& os);
};

#include "Cone_i.h"
