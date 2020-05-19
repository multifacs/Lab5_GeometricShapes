#pragma once
#include "Point.h"

template<class T>
class Line : public Point<T>
{
protected:
	T* B;
public:
	Line();
	Line(int n);
	Line(const Line& l);
	virtual ~Line();

	double GetLength() const;

	T* GetB() const;

	T*& SetB();

	ostream& print(ostream& os) override;
};

#include "Line_i.h"