#pragma once
#include <string>
#include <cstdlib>
#include <cctype>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter &copy);
public:
	ScalarConverter &operator=(const ScalarConverter &obj);
	~ScalarConverter();
	static void printInt(int i, long double ld);
	static void printChar(char c);
	static void printSpecial(const std::string &val);
	static void printFloat(float f);
	static void printDouble(double d);
	static void convert(const std::string &val);

	class InvalidInput : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

bool	isSpecial(const std::string &val);

bool	isFloat(const std::string &val);

bool	isDouble(const std::string &val);

bool	isInteger(const std::string &val);
