#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <string>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <map>

class PmergeMe {
private:
	static long jacobsthal[34];

	long getJacobsthal(int index);
	
	template <typename C>
	C mergeInsert(C &container);

	template <typename C>
	size_t binaryInsertSearch(int val, size_t size, const C &container);

	template <typename C>
	int findPos(C &container, int val);

	template <typename C>
	void rearrangePend(C &oldMain, C &newMain, C &pend);

	template <typename C>
	void insertPendChain(C &mainChain, C &pendChain);

	void print(std::vector<int> &vector);

	std::vector<int> vector;
	std::deque<int>  deque;
	std::set<int>    set;
	long long        vectorTime;
	long long        dequeTime;
	int              count;
	bool             straggler;

public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &ref);

	void validate(char **av);
	void printVector() const;
	void printSet() const;
	void sortVector();
	void sortDeque();
};

// Jacobsthal numbers: J(n) = J(n-1) + 2*J(n-2), J(0)=0, J(1)=1
long PmergeMe::jacobsthal[] = {
	0, 1, 1, 3, 5, 11, 21, 43, 85, 171,
	341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763,
	349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971,
	357913941, 715827883, 1431655765, 2863311531
};

long PmergeMe::getJacobsthal(int index)
{
	return (index >= 0 && index < 34) ? jacobsthal[index] : 0;
}

// template <typename C>
// void PmergeMe::print(std::vector<int> &vector)
// {
// 	for (size_t i = 0; i < vector.size(); ++i)
// 	{
// 		std::cout << vector[i];
// 		if (i != vector.size() - 1)
// 			std::cout << " ";
// 	}
// 	std::cout << "\n";
// }

template <typename C>
C PmergeMe::mergeInsert(C &container)
{
	if (container.size() <= 1)
		return container;

	if (container.size() == 2)
	{
		if (container[0] > container[1])
			std::swap(container[0], container[1]);
		return container;
	}

	C mainChain;
	C pendChain;
	bool hasStraggler = (container.size() % 2 == 1);

	for (size_t i = 0; i + 1 < container.size(); i += 2)
	{
		if (container[i] > container[i + 1])
		{
			mainChain.push_back(container[i]);
			pendChain.push_back(container[i + 1]);
		}
		else
		{
			mainChain.push_back(container[i + 1]);
			pendChain.push_back(container[i]);
		}
	}

	if (hasStraggler)
		pendChain.push_back(container.back());

	C sortedMain = mergeInsert(mainChain);
	rearrangePend(mainChain, sortedMain, pendChain);
	insertPendChain(sortedMain, pendChain);

	return sortedMain;
}

template <typename C>
size_t PmergeMe::binaryInsertSearch(int val, size_t size, const C &container)
{
	size_t low = 0;
	size_t high = size;

	while (low < high)
	{
		size_t mid = (low + high) / 2;
		if (container[mid] < val)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

template <typename C>
int PmergeMe::findPos(C &container, int val)
{
	for (size_t i = 0; i < container.size(); ++i)
	{
		if (container[i] == val)
			return static_cast<int>(i);
	}
	return -1;
}

template <typename C>
void PmergeMe::rearrangePend(C &oldMain, C &newMain, C &pend)
{
	if (oldMain.size() != newMain.size())
		return;

	C newPend(pend.size(), 0);
	std::map<int, int> oldIndexMap;
	for (size_t i = 0; i < oldMain.size(); ++i)
		oldIndexMap[oldMain[i]] = static_cast<int>(i);

	for (size_t i = 0; i < newMain.size(); ++i)
	{
		typename std::map<int, int>::iterator it = oldIndexMap.find(newMain[i]);
		if (it != oldIndexMap.end())
		{
			int idx = it->second;
			if (static_cast<size_t>(idx) < pend.size())
				newPend[i] = pend[idx];
		}
	}

	if (pend.size() > oldMain.size())
		newPend[newPend.size() - 1] = pend[pend.size() - 1];

	pend = newPend;
}

template <typename C>
void PmergeMe::insertPendChain(C &mainChain, C &pendChain)
{
	if (pendChain.empty())
		return;

	std::vector<int> insertionOrder;
	size_t remaining = pendChain.size();
	int jacobIndex = 1;

	while (getJacobsthal(jacobIndex + 1) < static_cast<long>(remaining))
		++jacobIndex;

	while (remaining > 0)
	{
		long curr = getJacobsthal(jacobIndex + 1);
		long prev = getJacobsthal(jacobIndex);
		long start = (prev > 1) ? prev : 1;
		long end = (curr < static_cast<long>(remaining)) ? curr : static_cast<long>(remaining);

		for (long i = end; i >= start; --i)
		{
			if (i <= static_cast<long>(remaining))
				insertionOrder.push_back(static_cast<int>(i - 1));
		}

		remaining = (prev > 1) ? static_cast<size_t>(prev - 1) : 0;
		if (curr >= static_cast<long>(remaining))
			--jacobIndex;
	}

	for (size_t i = 0; i < insertionOrder.size(); ++i)
	{
		int idx = insertionOrder[i];
		int val = pendChain[idx];
		size_t pos = binaryInsertSearch(val, mainChain.size(), mainChain);
		mainChain.insert(mainChain.begin() + pos, val);
	}
}

// PmergeMe::PmergeMe()
// 	: vectorTime(0), dequeTime(0), count(0), straggler(false)
// {
// }

// PmergeMe::~PmergeMe()
// {
// }

// PmergeMe::PmergeMe(const PmergeMe &copy)
// {
// 	*this = copy;
// }

// PmergeMe &PmergeMe::operator=(const PmergeMe &ref)
// {
// 	if (this != &ref)
// 	{
// 		vector = ref.vector;
// 		deque = ref.deque;
// 		set = ref.set;
// 		vectorTime = ref.vectorTime;
// 		dequeTime = ref.dequeTime;
// 		count = ref.count;
// 		straggler = ref.straggler;
// 	}
// 	return *this;
// }

// void PmergeMe::validate(char **av)
// {
// 	for (int i = 1; av[i]; ++i)
// 	{
// 		std::string s(av[i]);
// 		for (size_t j = 0; j < s.length(); ++j)
// 		{
// 			if (s[j] < '0' || s[j] > '9')
// 				throw std::exception();
// 		}
// 		char *end;
// 		long val = std::strtol(av[i], &end, 10);
// 		if (val < 0 || val > 2147483647L)
// 			throw std::exception();
// 		vector.push_back(static_cast<int>(val));
// 		deque.push_back(static_cast<int>(val));
// 		std::pair<std::set<int>::iterator, bool> res = set.insert(static_cast<int>(val));
// 		if (!res.second)
// 			throw std::exception(); // duplicate
// 	}
// 	count = static_cast<int>(set.size());
// 	straggler = (count % 2 == 1);
// }

// void PmergeMe::printVector() const
// {
// 	std::cout << "Before:\t";
// 	for (std::vector<int>::const_iterator it = vector.begin(); it != vector.end(); ++it)
// 	{
// 		if (it != vector.begin())
// 			std::cout << " ";
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// }

// void PmergeMe::printSet() const
// {
// 	std::cout << "After:\t";
// 	for (std::set<int>::const_iterator it = set.begin(); it != set.end(); ++it)
// 	{
// 		if (it != set.begin())
// 			std::cout << " ";
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// }

// void PmergeMe::sortVector()
// {
// 	timeval t;
// 	gettimeofday(&t, NULL);
// 	long long ms = (t.tv_sec * 1000000LL) + t.tv_usec;

// 	std::vector<int> vecCopy = vector;
// 	vector = mergeInsert(vecCopy);

// 	gettimeofday(&t, NULL);
// 	vectorTime = ((t.tv_sec * 1000000LL) + t.tv_usec) - ms;

// 	std::cout << "Time to process a range of " << count
// 			  << " elements with std::vector : " << vectorTime << " us" << std::endl;
// }

// void PmergeMe::sortDeque()
// {
// 	timeval t;
// 	gettimeofday(&t, NULL);
// 	long long ms = (t.tv_sec * 1000000LL) + t.tv_usec;

// 	std::deque<int> deqCopy = deque;
// 	deque = mergeInsert(deqCopy);

// 	gettimeofday(&t, NULL);
// 	dequeTime = ((t.tv_sec * 1000000LL) + t.tv_usec) - ms;

// 	std::cout << "Time to process a range of " << count
// 			  << " elements with std::deque  : " << dequeTime << " us" << std::endl;
// }

// Main function for testing
// int main(int ac, char **av)
// {
// 	if (ac < 2)
// 	{
// 		std::cerr << "Usage: " << av[0] << " <positive integers...>" << std::endl;
// 		return 1;
// 	}

// 	try
// 	{
// 		PmergeMe pmm;
// 		pmm.validate(av);
// 		pmm.printVector();
// 		pmm.printSet();
// 		pmm.sortVector();
// 		pmm.sortDeque();
// 		pmm.printVector();
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << "Error: invalid input" << std::endl;
// 		return 1;
// 	}

// 	return 0;
// }