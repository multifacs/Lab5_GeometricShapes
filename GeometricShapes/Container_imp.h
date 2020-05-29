#include "Container.h"

Container::Container()
{
	size = 0;
	Array = 0;
	names = {};
}

Container::Container(const Container& c)
{
	size = c.size;
	Array = c.Array;
	names = c.names;
}

Container::~Container()
{
	delete[] Array;
	names.clear();
}

Base* Container::operator[](const int i)
{
	return Array[i];
}

template<class A>
void Container::Add(A& elem, string name)
{
	Base** tmp = new Base * [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = Array[i];
	}
	delete[]Array;
	size++;
	Array = new Base * [size];
	for (int i = 0; i < size - 1; i++)
	{
		Array[i] = tmp[i];
	}
	Array[size - 1] = &elem;
	delete[]tmp;

	names.push_back(name);
}

void Container::Remove(int r)
{
	Base** tmp = new Base * [size];
	int j = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == r)
		{
			k = 1;
		}
		else
		{
			tmp[j] = Array[i];
			j++;
		}
	}
	if (k == 0)
		throw - 1;
	delete[] Array;
	Array = new Base * [size - 1];
	size = size - 1;
	for (int i = 0; i < size; i++)
		Array[i] = tmp[i];
	delete[] tmp;

	names.erase(names.begin() + r);
}

void Container::ShowAll()
{
	cout << "Objects in this container: " << endl;
	for (int i = 0; i < size; i++)
		cout << i << ") " << names[i] << " of " << typeid(*Array[i]).name() << endl;
}

inline void Container::Show(int i)
{
	//cout << "Object no. " << i << ":" << endl;
	cout << "Name: " << names[i] << endl << *Array[i] << endl;
}

template<class T>
inline void Container::CallPoint(int dims)
{
	vector<T> list(dims);
	cout << "Point A coordinates:" << endl;
	for (int i = 0; i < dims; i++)
		cin >> list[i];
	Array[size - 1] = new Point<T>(dims, list);
}

template<class T>
inline void Container::CallLine(int dims)
{
	vector<T> list(dims*2);
	cout << "Point A coordinates:" << endl;
	for (int i = 0; i < dims; i++)
		cin >> list[i];
	cout << "Point B coordinates:" << endl;
	for (int i = dims; i < dims*2; i++)
		cin >> list[i];
	Array[size - 1] = new Line<T>(dims, list);
}

template<class T>
inline void Container::CallTriangle(int dims)
{
	vector<T> list(dims * 3);
	cout << "Point A coordinates:" << endl;
	for (int i = 0; i < dims; i++)
		cin >> list[i];
	cout << "Point B coordinates:" << endl;
	for (int i = dims; i < dims * 2; i++)
		cin >> list[i];
	cout << "Point C coordinates:" << endl;
	for (int i = dims * 2; i < dims * 3; i++)
		cin >> list[i];
	Array[size - 1] = new Triangle<T>(dims, list);
}

template<class T>
inline void Container::CallQuadrilateral(int dims)
{
	vector<T> list(dims * 4);
	cout << "Point A coordinates:" << endl;
	for (int i = 0; i < dims; i++)
		cin >> list[i];
	cout << "Point B coordinates:" << endl;
	for (int i = dims; i < dims * 2; i++)
		cin >> list[i];
	cout << "Point C coordinates:" << endl;
	for (int i = dims * 2; i < dims * 3; i++)
		cin >> list[i];
	cout << "Point D coordinates:" << endl;
	for (int i = dims * 3; i < dims * 4; i++)
		cin >> list[i];
	Array[size - 1] = new Quadrilateral<T>(dims, list);
}

template<class T>
inline void Container::CallCircle(int dims)
{
	vector<T> list(dims * 2);
	cout << "Point A coordinates:" << endl;
	for (int i = 0; i < dims; i++)
		cin >> list[i];
	cout << "Point B coordinates:" << endl;
	for (int i = dims; i < dims * 2; i++)
		cin >> list[i];
	Array[size - 1] = new Circle<T>(dims, list);
}

template<class T>
inline void Container::CallSphere(int dims)
{
	vector<T> list(dims * 2);
	cout << "Point A coordinates:" << endl;
	for (int i = 0; i < dims; i++)
		cin >> list[i];
	cout << "Point B coordinates:" << endl;
	for (int i = dims; i < dims * 2; i++)
		cin >> list[i];
	Array[size - 1] = new Sphere<T>(dims, list);
}

template<class T>
inline void Container::CallEllipse(int dims)
{
	vector<T> list(dims * 3);
	cout << "Center (point C) coordinates:" << endl;
	for (int i = dims * 2; i < dims * 3; i++)
		cin >> list[i];
	cout << "Vertex (point A) coordinates:" << endl;
	for (int i = 0; i < dims; i++)
		cin >> list[i];
	cout << "Co-vertex (point B) coordinates:" << endl;
	for (int i = dims; i < dims * 2; i++)
		cin >> list[i];
	Array[size - 1] = new Ellipse<T>(dims, list);
}

inline void Container::Create(int shape_type, int coord_type, int dims, string name)
{
	Base** tmp = new Base * [size];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = Array[i];
	}
	delete[]Array;
	size++;
	Array = new Base * [size];
	for (int i = 0; i < size - 1; i++)
	{
		Array[i] = tmp[i];
	}
	switch (shape_type)
	{
	case 1:
		switch (coord_type)
		{
		case 1:
		{
			CallPoint<int>(dims);
			break;
		}
		case 2:
		{
			CallPoint<float>(dims);
			break;
		}
		case 3:
		{
			CallPoint<double>(dims);
			break;
		}
		}

		break;
	case 2:
	{

		switch (coord_type)
		{
		case 1:
		{
			CallLine<int>(dims);
			break;
		}
		case 2:
		{
			CallLine<float>(dims);
			break;
		}
		case 3:
		{
			CallLine<double>(dims);
			break;
		}
		}
		break;
	}
	case 3:
		switch (coord_type)
		{
		case 1:
			CallTriangle<int>(dims);
			break;
		case 2:
			CallTriangle<float>(dims);
			break;
		case 3:
			CallTriangle<double>(dims);
			break;
		}
		break;
	case 4:
		switch (coord_type)
		{
		case 1:
			CallQuadrilateral<int>(dims);
			break;
		case 2:
			CallQuadrilateral<float>(dims);
			break;
		case 3:
			CallQuadrilateral<double>(dims);
			break;
		}
		break;
	case 5:
		switch (coord_type)
		{
		case 1:
			CallCircle<int>(dims);
			break;
		case 2:
			CallCircle<float>(dims);
			break;
		case 3:
			CallCircle<double>(dims);
			break;
		}
		break;
	case 6:
		switch (coord_type)
		{
		case 1:
			CallSphere<int>(dims);
			break;
		case 2:
			CallSphere<float>(dims);
			break;
		case 3:
			CallSphere<double>(dims);
			break;
		}
		break;
	case 7:
		switch (coord_type)
		{
		case 1:
			CallEllipse<int>(dims);
			break;
		case 2:
			CallEllipse<float>(dims);
			break;
		case 3:
			CallEllipse<double>(dims);
			break;
		}
		break;
	}
	
	delete[]tmp;

	names.push_back(name);
}

inline int Container::GetSize()
{
	return size - 1;
}
