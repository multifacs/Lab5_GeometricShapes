#pragma once
#include "Triangle.h"

template<class T>
class Ellipse : public Triangle<T>
{
public:
	Ellipse() : Triangle<T>() {}
	Ellipse(int n) : Triangle<T>(n) {}
	Ellipse(const Ellipse& e) : Triangle<T>(e) {}
	virtual ~Ellipse() {};

	double GetAxisA() const;
	double GetAxisB() const;
	double GetPerimeter() const;
	double GetArea() const;

	ostream& print(ostream& os);
};

#include "Ellipse_imp.h"

template<class T>
inline double Ellipse<T>::GetAxisA() const
{
	double sum = 0;
	for (int i = 0; i < this->GetDim(); i++)
		sum += pow((this->C[i] - this->GetA()[i]), 2);
	return sqrt(sum);
}

template<class T>
inline double Ellipse<T>::GetAxisB() const
{
	double sum = 0;
	for (int i = 0; i < this->GetDim(); i++)
		sum += pow((this->C[i] - this->GetB()[i]), 2);
	return sqrt(sum);
}

template<class T>
inline double Ellipse<T>::GetPerimeter() const
{
	return 4 * (M_PI * GetAxisA() * GetAxisB() + pow((GetAxisA() - GetAxisB()), 2)) / (GetAxisA() + GetAxisB());
}

template<class T>
inline double Ellipse<T>::GetArea() const
{
	return M_PI * GetAxisA() * GetAxisB();
}

template<class T>
inline ostream& Ellipse<T>::print(ostream& os)
{
	os << "Type: " << typeid(*this).name() << endl <<
		"Dimensions: " << this->GetDim() << endl <<
		"Center (point C) coordinates: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetC()[i] << ", ";
		else
			os << this->GetC()[i];
	}
	os << ")" << endl;

	os << "Vertex (point A) coordinates: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetA()[i] << ", ";
		else
			os << this->GetA()[i];
	}
	os << ")" << endl;

	os << "Co-vertex (point B) coordinates: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->B[i] << ", ";
		else
			os << this->B[i];
	}
	os << ")" << endl;

	os << "Semi-major axis: " << GetAxisA() << endl;
	os << "Semi-minor axis: " << GetAxisB() << endl;
	os << "Area: " << GetArea() << endl;
	os << "Perimeter: " << GetPerimeter() << endl;

	return os;
}
