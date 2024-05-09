#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define INT_MAX 2147483647

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <sstream>

class PmergeMe
{
private:
	std::list<unsigned int>	_pmList;
	std::vector<unsigned int> _pmVec;
public:
	PmergeMe();
	~PmergeMe();

	//function member
	void	checkAndInput(const char* str);
	void	putDataToList(long long num);
	void	putDataToVec(long long num);
};

#endif
