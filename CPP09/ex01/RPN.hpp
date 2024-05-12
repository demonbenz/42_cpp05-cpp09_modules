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
	std::stack<int>	_rpn;
public:
	RPN();
	~RPN();

	RPN(RPN const & rhs);
	RPN & operator=(RPN const & rhs);

	//function member
	void	checkData(const char* argv);
	void	calculate(const char* argv);
	void	putStack(char c);
	void	popStack(char c);
	std::stack<int> const & getStack()const;
};

std::ostream & operator<<(std::ostream & o, RPN const & rhs);
std::ostream & operator<<(std::ostream & o, std::stack<int> const & rhs);

#endif
