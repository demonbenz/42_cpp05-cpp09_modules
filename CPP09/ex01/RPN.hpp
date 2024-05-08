#pragma once
#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>

class RPN
{
private:
	std::stack<int>	rpn;
public:
	RPN();
	~RPN();

	//function member
	void	checkData(const char* argv);
	void	calculate(const char* argv);

	void	putStack(char c);
	void	popStack(char c);
};

#endif
