#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
}

Serializer &Serializer::operator=(const Serializer &ref)
{
	(void)ref;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t converted = reinterpret_cast<uintptr_t>(ptr);
	return converted;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *reverted = reinterpret_cast<Data *>(raw);
	return reverted;
}
