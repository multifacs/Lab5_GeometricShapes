template<class T>
inline double Circle<T>::GetRadius() const
{
	return this->GetLength();
}

template<class T>
inline double Circle<T>::GetArea() const
{
	return pow(this->GetLength(), 2) * M_PI;
}

template<class T>
inline ostream& Circle<T>::print(ostream& os)
{
	os << "Dimensions: " << this->GetDim() << endl << "Point A coordinates: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetA()[i] << ", ";
		else
			os << this->GetA()[i];
	}
	os << ")" << endl;

	os << "Point B coordinates: (";
	for (int i = 0; i < this->GetDim(); i++)
	{
		if (i != this->GetDim() - 1)
			os << this->GetB()[i] << ", ";
		else
			os << this->GetB()[i];
	}
	os << ")" << endl;

	os << "Radius: " << GetRadius() << endl;
	os << "Area: " << GetArea() << endl;

	return os;
}
