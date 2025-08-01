#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->array = NULL;
	this->a_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	if (!n)
		throw std::runtime_error("size has to be bigger than 0.");
	this->array = new T[n];
	this->a_size = n;
}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
	if (!copy.a_size)
	{
		this->a_size = 0;
		this->array = NULL;
	}
	else
	{

		this->a_size = copy.a_size;
		this->array = new T[this->a_size];
		unsigned int i = 0;
		while (i < this->a_size)
		{
			this->array[i] = copy.array[i];
			i++;
		}
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &ref)
{
	if (this->a_size > 0)
		delete[] this->array;
	if (!ref.a_size)
	{
		this->a_size = 0;
		this->array = NULL;
	}
	else
	{
		this->a_size = ref.a_size;
		this->array = new T[this->a_size];
		unsigned int i = 0;
		while (i < this->a_size)
		{
			this->array[i] = ref.array[i];
			i++;
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	if (this->a_size > 0)
		delete[] this->array;
	this->array = NULL;
}

template <typename T>
const T &Array<T>::operator[](unsigned int i) const
{
	if (!this->a_size)
		throw std::runtime_error("Empty array.");

	if (i > this->a_size - 1)
		throw std::runtime_error("Index out of bounds.");
	return this->array[i];
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (!this->a_size)
		throw std::runtime_error("Empty array.");

	if (i > this->a_size - 1)
		throw std::runtime_error("Index out of bounds.");
	return this->array[i];
	
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->a_size;
}
