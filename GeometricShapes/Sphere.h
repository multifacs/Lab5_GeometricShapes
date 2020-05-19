#pragma once
#include "Circle.h"

template<class T>
class Sphere : public Circle<T>
{
	using Circle<T>::GetArea;
public:
	Sphere() : Circle<T>() {}
	Sphere(int n) : Circle<T>(n) {}
	Sphere(const Sphere& s) : Circle<T>(s) {}
	virtual ~Sphere() {};

	double GetVolume() const;

	ostream& print(ostream& os);
};

#include "Sphere_imp.h"
