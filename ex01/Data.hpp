#pragma once

class Data
{
private:
	int	_time;
public:
	Data();
	Data(int time);
	Data(Data &copy);
	~Data();
	Data & operator=(const Data &obj);
	int		getTime() const;
	void	setTime(int time);
};
