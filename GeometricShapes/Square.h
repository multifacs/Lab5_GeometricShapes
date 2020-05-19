#pragma once
#include "Triangle.h"

template<class T>
class Square : public Triangle<T>
{
protected:
	T* D;
public:
	Square();
	Square(int n);
	Square(const Square& q);
	virtual ~Square();

	T* GetD() const;
	T*& SetD();

	double GetPerimeter() const;
	double GetArea() const;
	bool IsSquare() const;

	ostream& print(ostream& os) override;
};

#include "Square_imp.h"