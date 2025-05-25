#pragma once

#include <algorithm>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"
