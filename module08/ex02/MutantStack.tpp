#include "MutantStack.hpp"

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return this->c.end();

}