#include "PmergeMe.hpp"
#include <cassert>

long	PmergeMe::jacobsthal[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 
	5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765,
	2863311531, 5726623061, 11453246123};

long PmergeMe::getJacobsthal(int index)
{
	return (index >= 0 && index < 34) ? jacobsthal[index] : 0;
}

template <typename C>
C PmergeMe::mergeInsert(C &container)
{
	if (container.size() == 1)
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
	for (size_t i = 0; i < container.size(); i+=2)
	{
		if (i + 1 != container.size())
		{
			bool firstIsBigger = container[i] > container[i + 1];
			int begin = firstIsBigger ? container[i] : container[i + 1];
			int end   = firstIsBigger ? container[i + 1] : container[i];
			mainChain.push_back(begin);
			pendChain.push_back(end);
		}
	}
	if (hasStraggler)
		pendChain.push_back(container.back());

	C sortedMain = this->mergeInsert(mainChain);
	this->rearrangePend(mainChain, sortedMain, pendChain);
	this->insertPendChain(sortedMain, pendChain);
	return sortedMain;
}

template <typename C>
size_t PmergeMe::binaryInsertSearch(int val, size_t cap, const C &container)
{
    size_t low = 0;
    size_t high = cap;

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
	for (size_t i = 0; i < container.size(); i++)
		if (container[i] == val)
			return i;
	return -1;
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

template <typename C>
void PmergeMe::rearrangePend(C &oldMain, C &newMain, C &pendChain)
{
    size_t mainSize = oldMain.size();
    size_t pendSize = pendChain.size();
    if (mainSize == 0 || (mainSize != pendSize && mainSize != pendSize - 1))
        return;

    C newPend(pendSize, 0);
    for (size_t i = 0; i < mainSize; ++i)
    {
        int value = oldMain[i];
        size_t newPos = 0;
        bool found = false;

        for (size_t j = 0; j < newMain.size(); ++j)
        {
            if (newMain[j] == value)
            {
                newPos = j;
                found = true;
                break;
            }
        }

        if (found && i < pendSize)
            newPend[newPos] = pendChain[i];
    }
    if (pendSize > mainSize)
        newPend[newPend.size() - 1] = pendChain[pendSize - 1];

    pendChain = newPend;
}

PmergeMe::PmergeMe()
{
	this->vectorTime = 0;
	this->dequeTime = 0;
	this->count = 0;
	this->straggler = false;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &ref)
{
	this->vector = ref.vector;
	this->vectorTime = ref.vectorTime;
	this->deque = ref.deque;
	this->dequeTime = ref.dequeTime;
	return *this;
}

void PmergeMe::validate(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		if (std::string(av[i]).find_first_not_of("0123456789") != std::string::npos)
			throw (std::invalid_argument("Error: Only numerical inputs"));
		int val;
		std::stringstream ss(av[i]);
		if (!(ss >> val) || !(ss.eof()))
			throw (std::invalid_argument("Error: Overflow detected"));
		if (val < 0)
			throw (std::invalid_argument("Error: Only positive integers"));
		this->vector.push_back(val);
		this->deque.push_back(val);
		this->set.insert(val);
	}
	if (this->set.size() < this->vector.size())
		throw (std::invalid_argument("Error: Duplicates not allowed"));
	this->count = this->set.size();
	if (this->count % 2 == 1)
		this->straggler = true;
}

void PmergeMe::printVector() const
{
	std::cout << "Before:	";
	std::vector<int>::const_iterator check;
	for (std::vector<int>::const_iterator it = this->vector.begin(); it != this->vector.end(); ++it)
	{
		check = it;
		std::cout << *it;
		if (++check != this->vector.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printSet() const
{
	std::cout << "After:	";
	std::set<int>::iterator check;
	for (std::set<int>::iterator it = this->set.begin(); it != this->set.end(); ++it)
	{
		check = it;
		std::cout << *it;
		if (++check != this->set.end())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::sortVector()
{
	struct timeval	t;
	long long		ms;
	gettimeofday(&t, NULL);
	ms = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	this->vector = mergeInsert(this->vector);
	gettimeofday(&t, NULL);
	this->vectorTime = ((t.tv_sec * 1000) + (t.tv_usec / 1000)) - ms;
	std::cout << "Time to process a range of " << count << " elements with std::vector	: " << this->vectorTime << " us" << std::endl;
}

void PmergeMe::sortDeque()
{
	struct timeval	t;
	long long		ms;
	gettimeofday(&t, NULL);
	ms = (t.tv_sec * 1000) + (t.tv_usec / 1000);
	this->deque = mergeInsert(this->deque);
	gettimeofday(&t, NULL);
	this->dequeTime = (t.tv_sec * 1000) + (t.tv_usec / 1000) - ms;
	std::cout << "Time to process a range of " << count << " elements with std::deque	: " << this->dequeTime << " us" << std::endl;
}
