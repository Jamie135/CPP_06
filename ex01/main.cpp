#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data *data = new Data(2009);
	Serializer serial;
	uintptr_t	ptr;

	std::cout << "Data ptr: " << data << std::endl;
	ptr = serial.serialize(data);
	std::cout << "Serialized into: " << ptr << std::endl;
	std::cout << "Deserialized into: " << serial.deserialize(ptr) << std::endl;
	delete data;
}
