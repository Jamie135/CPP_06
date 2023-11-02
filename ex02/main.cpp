#include "Identifier.hpp"

int	main()
{
	srand (time(0));
	Base *ptr;
	
	std::cout << "Pointer test" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		ptr = generate();
		std::cout << "Identify is ";
		identify(ptr);
		delete ptr;
		usleep(1000);
	}
	std::cout << "Reference test" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base	&ref = *generate();
		std::cout << "Identify is ";
		identify(ref);
		delete &ref;
		usleep(1000);
	}
	return (0);
}
