#pragma once
#include "Base.h"

template<class T>
class Point : public Base
{
protected:
	int dim;
	T* A;
public:
	Point();
	Point(int n);
	Point(const Point& p);
	virtual ~Point();

	T* GetA() const;
	int GetDim() const;

	T*& SetA();
	int& SetDim();

	ostream& print(ostream& os) override;
};

#include "Point_i.h"