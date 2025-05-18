#pragma once
#include <iostream>

template <typename variable>
void	print(variable &rando)
{
	std::cout << rando << std::endl;
}


template <typename variable>
void iter(variable *array, unsigned int length, void (*function)(variable &))
{
	for (unsigned int i = 0; i < length; i++){
		function(array[i]);
	}
}
