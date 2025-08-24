#include <algorithm>
#include <exception>
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <deque>
#include <set>
#include <sys/time.h>
#include <cmath>
#include <limits.h>
#include <sstream>

class PmergeMe
{
	private:
		long long			vectorTime;
		long long			dequeTime;
		std::vector<int>	vector;
		std::deque<int>		deque;
		std::set<int>		set;
		std::pair<int, int>	pair;
		int					count;
		bool				straggler;
		static long			jacobsthal[];


		template<typename C>
		C mergeInsert(C &container);

	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &ref);
		
		template <typename C>
		size_t binaryInsertSearch(int val, size_t cap, const C &container);

		template<typename C>
		int	findPos(C &container, int val);

		template<typename C>
		void insertPendChain(C &mainChain, C &pendChain);

		template<typename C>
		void rearrangePend(C &old, C &main, C &pend);

		long getJacobsthal(int index);
		void validate(char **av);
		void printVector() const;
		void printSet() const;
		void sortVector();
		void sortDeque();
};
