#include "Data.hpp"

Data::Data() : _time(0)
{}

Data::Data(int time) : _time(time)
{}

Data::Data(Data &copy) : _time(copy.getTime())
{}

Data::~Data()
{}

Data & Data::operator=(const Data &obj) {
	if (this != &obj)
		this->_time = obj.getTime();
	return (*this);
}

int		Data::getTime() const
{
	return (_time);
}

void	Data::setTime(int time)
{
	_time = time;
}