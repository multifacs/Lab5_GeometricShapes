#pragma once
#include "Triangle.h"

template<class T>
class Quadrilateral : public Triangle<T>
{
protected:
	T* D;
public:
	Quadrilateral();
	Quadrilateral(int n);
	Quadrilateral(int n, const vector<T>& list);
	Quadrilateral(const Quadrilateral& q);
	virtual ~Quadrilateral();

	T* GetD() const;
	T*& SetD();

	double GetPerimeter() const;
	double GetArea() const;
	bool IsSquare() const;

	ostream& print(ostream& os) override;
};

#include "Quadrilateral_imp.h"