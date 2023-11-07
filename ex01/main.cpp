#include "Serializer.hpp"

int main()
{
	Data	ptr1;
	ptr1.name = "Toto";
	ptr1.age = 42;

	std::cout << "Here is the original data:" <<
				"\n\taddress: " << &ptr1 <<
				"\n\tname: " << ptr1.name <<
				"\n\tage: " << ptr1.age <<
	std::endl;

	uintptr_t	a = Serializer::serialize(&ptr1);
	Data	*ptr2 = Serializer::deserialize(a);

	std::cout << "Here is the reserialized data:" <<
				"\n\taddress: " << ptr2 <<
				"\n\tname: " << ptr2->name <<
				"\n\tage: " << ptr2->age <<
	std::endl;

	return (0);
}
