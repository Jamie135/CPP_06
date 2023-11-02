#include "Identifier.hpp"

Base*	generate()
{
	std::srand(std::time(0));
	int choice = std::rand() % 3;
	switch (choice) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (0);
	}
}

void	identify(Base* p)
{
	if (!p) {
		std::cerr << "NULL ptr" << std::endl;
	} else if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cerr << "Unknown" << std::endl;
	}
}

void	identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	} catch (const std::exception &e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void) b;
			std::cout << "B" << std::endl;
		} catch (const std::exception &e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void) c;
				std::cout << "C" << std::endl;
			} catch (const std::exception &e) {
				std::cerr << "Unknown" << std::endl;
			}
		}
	}
}
