#include "Span.hpp"

Span::Span(unsigned int N)
{
	this->capacity = N;
}

Span::Span(const Span &copy)
{
	this->capacity = copy.capacity;
	this->nums = copy.nums;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &ref)
{
	if (this != &ref)
	{
		this->capacity = ref.capacity;
		this->nums = ref.nums;
	}
	return *this;
}

unsigned int Span::getCap() const
{
	return this->capacity;
}

void Span::addNumber(int _num)
{
	if (this->nums.size() >= this->capacity)
		throw std::runtime_error("Span is full");
	this->nums.push_back(_num);
}

int Span::shortestSpan()
{
	if (this->nums.size() < 2)
		throw std::runtime_error("Can't find span.");
	std::vector<int> copy = this->nums;
	std::sort(copy.begin(), copy.end());
	int min = copy[1] - copy[0];
	for (size_t i = 2; i < copy.size(); i++)
	{
		int temp = copy[i] - copy[i - 1];
		if (temp < min)
			min = temp;
	}
	return min;
}

int Span::longestSpan()
{
	if (this->nums.size() < 2)
		throw std::runtime_error("Can't find span.");
	int max_elem = *std::max_element(this->nums.begin(), this->nums.end());
	int min_elem = *std::min_element(this->nums.begin(), this->nums.end());
	return (max_elem - min_elem);
}
