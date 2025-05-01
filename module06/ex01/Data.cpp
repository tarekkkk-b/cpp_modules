#include "Data.hpp"

Data::Data()
{
	this->num = 0;
}

Data::~Data()
{
}

Data::Data(const Data &copy)
{
	this->num = copy.num;
}

Data &Data::operator=(const Data &ref)
{
	this->num = ref.num;
	return *this;
}

Data::Data(const int _num)
{
	this->num = _num;
}

int Data::getNum() const
{
	return this->num;
}
