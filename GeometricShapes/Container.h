#pragma once
#include <vector>
#include "Base.h"

using namespace std;

class Container
{
protected:
	Base** Array;
	vector<string> names;
	int size;
public:
	Container();
	Container(const Container& c);
	virtual ~Container();

	template <class A>
	void Add(A& elem, string name);
	void Remove(int r);
	void ShowAll();
	void Show(int i);

	template<class T>
	void CallPoint(int dims);
	template<class T>
	void CallLine(int dims);
	template<class T>
	void CallTriangle(int dims);
	template<class T>
	void CallQuadrilateral(int dims);
	template<class T>
	void CallCircle(int dims);
	template<class T>
	void CallSphere(int dims);
	template<class T>
	void CallEllipse(int dims);

	void Create(int shape_type, int coord_type, int dims, string name);

	int GetSize();

	Base* operator[](const int i);
};

#include "Container_imp.h"