#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	this->vectorTime = 0;
	this->dequeTime = 0;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	this->vector = copy.vector;
	this->vectorTime = copy.vectorTime;
	this->deque = copy.deque;
	this->dequeTime = copy.dequeTime;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref)
{
	*this = ref;
	return *this;
}

void PmergeMe::validate(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		if (std::string(av[i]).find_first_not_of("0123456789") != std::string::npos)
			throw std::exception();
		int val = std::atoi(av[i]);
		if (val < 0)
			throw std::exception();
		std::vector<int>::iterator it;
		if (i > 1)
		{
			it = std::find(this->vector.begin(), this->vector.end(), val);
			if (it != this->vector.end())
				throw std::exception();
		}
		this->vector.push_back(val);
		this->deque.push_back(val);
	}
}

long long PmergeMe::getVectorTime() const
{
	return this->vectorTime;
}

long long PmergeMe::getDequeTime() const
{
	return this->dequeTime;
}
