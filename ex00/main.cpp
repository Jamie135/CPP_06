#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		try {
			ScalarConverter::convert(argv[1]);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
}