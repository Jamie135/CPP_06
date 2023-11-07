#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string	name;
	size_t		age;
}				Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
	public:
		~Serializer();
		Serializer &operator=(const Serializer &src);

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};