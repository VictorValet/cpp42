#include "Data.hpp"

Data::Data(void):
i(0)
{
	return ;
}

Data::Data(int x):
i(x)
{
	return ;
}

Data::Data(const Data &original)
{
	*this = original;
	return ;
}

Data	&Data::operator=(const Data &original)
{
	this->i = original.getI();
	return (*this);
}

Data::~Data(void)
{
	return ;
}

int		Data::getI(void) const
{
	return(this->i);
}

void	Data::setI(int x)
{
	this->i = x;
}
