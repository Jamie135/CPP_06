#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	(void)copy;
};

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

const char *ScalarConverter::InvalidInput::what() const throw()
{
	return ("Invalid input");
}

bool	isSpecial(const std::string &val)
{
	return ( val == "nan" || val == "nanf"
			|| val == "-inff" || val =="+inff"
			||  val == "-inf" || val == "+inf");
}

bool	isDFDigit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	if (c == '+' || c == 'e' || c == 'E')
		return (true);
	return (false);
}

bool	isFloat(const std::string &val)
{
	int	flag = 0;
	for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.size(); i++)
	{
		if (flag == 0 && isDFDigit(val[i]))
			flag = 1;
		else if (flag == 0 && !isDFDigit(val[i]))
			return (false);
		else if (flag == 1 && val[i] == '.')
			flag = 2;
		else if (flag == 1 && val[i] != '.' && !isDFDigit(val[i]))
			return (false);
		else if (flag == 2 && isDFDigit(val[i]))
			flag = 3;
		else if ((flag == 2 || flag == 3) && !isDFDigit(val[i]) && val[i] != 'f')
			return (false);
		else if (flag == 3 && val[i] == 'f')
			flag = 4;
	}
	return (flag == 4);
}

bool	isDouble(const std::string &val)
{
	int	d = 0;
	for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.size(); i++)
	{
		if (d == 0 && isDFDigit(val[i]))
			d = 1;
		else if (d == 0 && !isDFDigit(val[i]))
			return (false);
		else if (d == 1 && val[i] == '.')
			d = 2;
		else if (d == 1 && val[i] != '.' && !isDFDigit(val[i]))
			return (false);
		else if (d == 2 && isDFDigit(val[i]))
			d = 3;
		else if ((d == 2 || d == 3) && !isDFDigit(val[i]))
			return (false);
	}
	return (d == 3);
}

bool	isInteger(const std::string &val)
{
	for (unsigned long i = (val[0] == '+' || val[0] == '-') ? 1 : 0; i < val.length(); i++)
	{
		if (!std::isdigit(val[i]))
			return (false);
	}
	return (true);
}

void	ScalarConverter::printInt(long double ld)
{
	int	i = static_cast<int>(ld);
	char c = static_cast<char>(ld);
	float f = static_cast<float>(ld);
	double d = static_cast<double>(ld);

	std::cout << "char: " << (i > 127 || i < 0 ? "impossible"
		: (std::isprint(i) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	if (ld <= std::numeric_limits<int>::max() && ld >= std::numeric_limits<int>::min())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void	ScalarConverter::printChar(char c)
{
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
}

void	ScalarConverter::printSpecial(const std::string &val)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << val << (val == "nanf" || val == "-inff" || val == "+inff" ? "" : "f") << std::endl;
	std::cout << "double: " << (val == "nanf" ? "nan" : val) << std::endl;
}

void 	ScalarConverter::printFloat(long double ld)
{
	char c = static_cast<char>(ld);
	int i = static_cast<int>(ld);
	float f = static_cast<float>(ld);
	double d = static_cast<double>(ld);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	if (ld >= std::numeric_limits<int>::min() && ld <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (ld >= std::numeric_limits<float>::min() && ld <= std::numeric_limits<float>::max())
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (ld >= std::numeric_limits<double>::min() && ld <= std::numeric_limits<double>::max())
		std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
}

void 	ScalarConverter::printDouble(long double ld)
{
	char c = static_cast<char>(ld);
	int i = static_cast<int>(ld);
	float f = static_cast<float>(ld);
	double d = static_cast<double>(ld);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	if (ld >= std::numeric_limits<int>::min() && ld <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (ld >= std::numeric_limits<float>::min() && ld <= std::numeric_limits<float>::max())
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (ld >= std::numeric_limits<double>::min() && ld <= std::numeric_limits<double>::max())
		std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
}

void	ScalarConverter::convert(const std::string &val)
{
	if (val.size() == 0)
		throw ScalarConverter::InvalidInput();
	else if (val.size() == 1)
	{
		if (std::isdigit(val[0]))
		{
			long double d = std::strtod(val.c_str(), NULL);
			ScalarConverter::printInt(d);
		}
		else
		{
			ScalarConverter::printChar(val[0]);
		}
	}
	else if (isSpecial(val))
		ScalarConverter::printSpecial(val);
	else
	{
		if (isFloat(val))
		{
			long double f = std::strtod(val.c_str(), NULL);
			ScalarConverter::printFloat(f);
		}
		else if (isInteger(val))
		{
			long double d = std::strtod(val.c_str(), NULL);
			ScalarConverter::printInt(d);
		}
		else if (isDouble(val))
		{
			char 	*end;
			float	d = std::strtod(val.c_str(), &end);
			if (*end == '\0')
				ScalarConverter::printDouble(d);
			else
				throw ScalarConverter::InvalidInput();
		}
		else
			throw ScalarConverter::InvalidInput();
	}
}
