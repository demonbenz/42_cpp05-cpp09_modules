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