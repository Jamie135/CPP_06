#include "Serializer.hpp"

int main()
{
	Data ptr1;
	ptr1.name = "Toto";
	ptr1.age = 42;

	Data ptr2;
	ptr2.name = "Titi";
	ptr2.age = 24;

	std::cout << "Here is the original structs:" <<
				"\n\taddress: " << &ptr1 <<
				"\n\tname: " << ptr1.name <<
				"\n\tage: " << ptr1.age <<
	std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\tname: " << ptr2.name <<
				"\n\tage: " << ptr2.age <<
	std::endl << std::endl;

	Serializer a;

	Data *ptr3 = a.unserialize(a.serialize(&ptr1));

	std::cout << "Here is the reserialized structs:" <<
				"\n\taddress: " << ptr3 <<
				"\n\tname: " << ptr3->name <<
				"\n\tage: " << ptr3->age <<
	std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\tname: " << ptr2.name <<
				"\n\tage: " << ptr2.age <<
	std::endl << std::endl;

	return (0);
}
