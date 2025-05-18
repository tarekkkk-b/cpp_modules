#pragma once
#include <iostream>
#include <stdlib.h>

template <typename T>
class Array
{
	private:
	T				*array;
	unsigned int	a_size;
	
	public:
	Array();
	Array(unsigned int n);
	Array(const Array &copy);
	Array &operator=(const Array &ref);
	
	~Array();
	
	const T &operator[](unsigned int i) const;
	T &operator[](unsigned int i);
	
	unsigned int size() const;
	
};

#include "Array.tpp"