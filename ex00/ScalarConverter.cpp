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

void	ScalarConverter::printInt(int i, long double ld)
{
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

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

void 	ScalarConverter::printFloat(float f)
{
	char c = static_cast<char>(f);
	int i = static_cast<int>(f);
	double d = static_cast<double>(f);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<double>::min() && d <= std::numeric_limits<double>::max())
		std::cout << "double: " << d << (d == std::floor(d) ? ".0" : "") << std::endl;
	else
		std::cout << "double: " << "impossible" << std::endl;
}

void 	ScalarConverter::printDouble(double d)
{
	char c = static_cast<char>(d);
	int i = static_cast<int>(d);
	float f = static_cast<float>(d);

	std::cout << "char: " << (c > 127 || c < 0 ? "impossible"
		: (std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable"))
		<< std::endl;
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<float>::min() && d <= std::numeric_limits<float>::max())
		std::cout << "float: " << f << (f == std::floor(f) ? ".0f" : "f") << std::endl;
	else
		std::cout << "float: " << "impossible" << std::endl;
	if (d >= std::numeric_limits<double>::min() && d <= std::numeric_limits<double>::max())
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
			int d = std::atoi(val.c_str());
			long double ld = std::strtod(val.c_str(), NULL);
			ScalarConverter::printInt(d, ld);
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
			float f = std::atof(val.c_str());
			ScalarConverter::printFloat(f);
		}
		else if (isInteger(val))
		{
			int d = std::atoi(val.c_str());
			long double ld = std::strtod(val.c_str(), NULL);
			ScalarConverter::printInt(d, ld);
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
