#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <exception>
#include <ctime>

class Span
{
private:
	std::vector<int>	_data;
	unsigned int _maxSize;
public:
	Span();
	Span(unsigned int N);
	~Span();
	
	// copy constructor
	Span (const Span& rhs);
	Span & operator=(const Span & rhs);

	// member function
	void addNumber(const int num);
	int shortestSpan();
	int longestSpan();
	std::string toString() const;
	Span & fillSpan();
	
	// getter setter
	void setData(const unsigned int index, int value);
	int getData(const unsigned int index);
	unsigned int getSize();
};

std::ostream & operator<<(std::ostream & o, const Span & rhs);
#endif
