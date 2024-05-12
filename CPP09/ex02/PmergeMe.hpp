#pragma once
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define INT_MAX 2147483647

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <iomanip>

class PmergeMe
{
private:
	std::deque<unsigned int>	_pmDeque;
	std::vector<unsigned int> 	_pmVec;
public:
	PmergeMe();
	~PmergeMe();

	PmergeMe(const PmergeMe & rhs);
	PmergeMe & operator=(const PmergeMe & rhs);

	//function member
	void	checkAndInput(const char* str);
	std::vector<unsigned int> &		getVec();
	std::deque<unsigned int> &		getDeque();

	// Deque	
	void	putDataToDeque(long long num);
	void	printDeque();
	double	sortDeque();
	void	insertionSortDeque(std::deque<unsigned int> & arr);
	void	mergeInsertSortDeque(std::deque<unsigned int> & arr);
	void	mergeISSortHelpDeque(std::deque<unsigned int> & arr, std::deque<unsigned int> & temp , int left, int right);
	void	mergeDeque(std::deque<unsigned int> & arr,std::deque<unsigned int> & temp, int left, int mid, int right);

	// Vector
	void	putDataToVec(long long num);
	void	printVec();
	double	sortVec();
	void	insertionSortVec(std::vector<unsigned int> & arr);
	void	mergeInsertSortVec(std::vector<unsigned int> & arr);
	void	mergeISSortHelpVec(std::vector<unsigned int> & arr, std::vector<unsigned int> & temp , int left, int right);
	void	mergeVec(std::vector<unsigned int> & arr,std::vector<unsigned int> & temp, int left, int mid, int right);
};

std::ostream & operator<<(std::ostream & o, std::vector<unsigned int> const & arr);
std::ostream & operator<<(std::ostream & o, std::deque<unsigned int> const & arr);

#endif
