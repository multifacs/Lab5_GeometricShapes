#pragma once
#include "Line.h"

template<class T>
class Triangle : public Line<T>
{
protected:
	T* C;
public:
	Triangle();
	Triangle(int n);
	Triangle(const Triangle& t);
	virtual ~Triangle();

	virtual double GetPerimeter() const;
	virtual double GetArea() const;

	T* GetC() const;
	T*& SetC();

	ostream& print(ostream& os) override;
};

#include "Triangle_i.h"
