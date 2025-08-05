#include <string>
#include <exception>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		long long			vectorTime;
		long long			dequeTime;
		std::vector<int>	vector;
		std::deque<int>		deque;

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &ref);

		void validate(char **av);

		long long getVectorTime() const;
		long long getDequeTime() const;
};