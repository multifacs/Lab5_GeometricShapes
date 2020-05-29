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
	Line(int n, const vector<T>& list);
	Line(const Line& l);
	Line(Point<T>&) {};
	virtual ~Line();

	double GetLength() const;

	T* GetB() const;

	T*& SetB();

	ostream& print(ostream& os) override;
};

#include "Line_imp.h"