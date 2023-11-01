#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer &copy)
{
	(void)copy;
}

Serializer::~Serializer()
{}

Serializer & Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
