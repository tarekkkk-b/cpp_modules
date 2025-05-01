#include "Serializer.hpp"

int main()
{
	Data *data = new Data();

	std::cout << "Original data:	" << data << std::endl;
	uintptr_t convert = Serializer::serialize(data);
	Data *newData = Serializer::deserialize(convert);
	std::cout << "New data:	" << newData << std::endl;

	delete data;
}