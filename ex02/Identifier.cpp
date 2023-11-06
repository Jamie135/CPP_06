#include "Identifier.hpp"

Base*	generate()
{
	int		gen = rand() % 3;
	
	switch (gen)
	{
		case 0 :
			std::cout << "A has been generated" << std::endl;
			return new A();
			break;
		
		case 1 :
			std::cout << "B has been generated" << std::endl;
			return new B();
			break;
		
		case 2 :
			std::cout << "C has been generated" << std::endl;
			return new C();
			break;
		
		default:
			return NULL;
			break;
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
