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
	void Add(A& obj, string name);

	void Remove(int r);
	void ShowAll();

	void Show(int i);

	Base* operator[](const int i);
};

#include "Container_i.h"