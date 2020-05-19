template<class T>
inline double Sphere<T>::GetVolume() const
{
	return (4.0 / 3) * pow(this->GetRadius(), 3) * M_PI;
}


template<class T>
inline ostream& Sphere<T>::print(ostream& os)
{
	os << "Type: " << typeid(*this).name() << endl <<
		"Dimensions: " << this->GetDim() << endl <<
		"Point A coordinates: (";
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

	os << "Radius: " << this->GetRadius() << endl;
	os << "Volume: " << GetVolume() << endl;

	return os;
}