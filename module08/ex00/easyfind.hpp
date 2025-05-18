#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(T &container, int value)
{
	typename T::const_iterator iterator = container.begin();
	while (iterator != container.end())
	{
		if (*iterator == value)
			return iterator;
		++iterator;
	}
	throw std::runtime_error("Value not found");
}
