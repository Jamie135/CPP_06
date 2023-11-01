#pragma once

#include <stdint.h>
#include "Data.hpp"

class	Serializer {
	private:
		Serializer();
		Serializer(Serializer &copy);
	public:
		~Serializer();
		Serializer & operator=(const Serializer &obj);

		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};
