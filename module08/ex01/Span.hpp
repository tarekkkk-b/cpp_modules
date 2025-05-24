#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
	private:
		unsigned int capacity;
		std::vector<int> nums;
		Span();

	public:
		Span(unsigned int N);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &ref);

		unsigned int getCap() const;

		void addNumber(int _num);

		template <typename iterator>
		void addNumber(iterator start, iterator end);
		int shortestSpan();
		int longestSpan();
};

template <typename iterator>
inline void Span::addNumber(iterator start, iterator end)
{
	if (this->nums.size() + std::distance(start, end) > this->capacity)
		throw std::runtime_error("Span is full");
	this->nums.insert(this->nums.end(), start, end);	
}
