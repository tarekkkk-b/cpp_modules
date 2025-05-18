#include "iter.hpp"

int main()
{
	std::string strs[] = {"hello", "there", "world"};
	iter(strs, 8, print<std::string>);
	

	int nums[] = {5, 7, 3, 2, 2, 65, 7, 13, -12, 5};
	iter(nums, 10, print<int>);
	
}