#pragma once
#include <iostream>

template <typename variable>
void swap(variable &a, variable &b)
{
	variable temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename variable>
variable &max(variable &a, variable &b)
{
	if (a > b)
		return a;
	return b;
}

template <typename variable>
variable &min(variable &a, variable &b)
{
	if (a < b)
		return a;
	return b;
}