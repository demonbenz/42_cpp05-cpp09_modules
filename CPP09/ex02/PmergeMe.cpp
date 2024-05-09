#include "PmergeMe.hpp"

// Reverse Polish Notation Calculator(RPN)
PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

void  PmergeMe::checkAndInput(const char * str)
{
	long long num;
	std::istringstream iss(str);
	iss >> num;

	if (num < 0)
		throw std::out_of_range("not negative number.");
	else if (num > INT_MAX)
		throw std::out_of_range("number out of range.");
	else{
		while(*str)
		{
			if (!isdigit(*str) && *str != ' ')
				throw std::out_of_range("not number because contain alphabet.");
			++str;
		}
	}
	putDataToList(num);
	putDataToVec(num);
}

void	PmergeMe::putDataToList(long long num)
{
	_pmList.push_back(static_cast<unsigned int>(num));
}

void	PmergeMe::putDataToVec(long long num)
{
	_pmVec.push_back(static_cast<unsigned int>(num));
}

void	PmergeMe::printList()
{
	std::list<unsigned int>::iterator it = _pmList.begin();
	for (;it != _pmList.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

void	PmergeMe::printVec()
{
	std::vector<unsigned int>::iterator it = _pmVec.begin();
	for (;it != _pmVec.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

double	PmergeMe::sortVec()
{
	clock_t startTime = clock();

	//sort
	std::sort(_pmVec.begin(), _pmVec.end());// <---------Change This to Merge-insertion sort Agorithm.
	clock_t endTime = clock();
	double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

	return (totalTime);
}

double	PmergeMe::sortList()
{
	clock_t startTime = clock();

	//sort
	_pmList.sort();// <---------Change This to Merge-insertion sort Agorithm.
	clock_t endTime = clock();
	double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

	return (totalTime);
}