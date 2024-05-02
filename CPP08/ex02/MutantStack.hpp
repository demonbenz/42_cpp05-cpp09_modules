#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack :public std::stack<T>
{
private:
public:
	MutantStack();
	~MutantStack();
	
	//function member
	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin()
	{
		return (this->c.begin());
	}
	iterator end()
	{
		return (this->c.end());
	}
	MutantStack (const MutantStack& rhs)
	{
		*this = rhs;
	}
	MutantStack & operator=(const MutantStack & rhs)
	{
		if (this != &rhs)
		{
			std::stack<T>::operator=(rhs);
		}
		return (*this);
	}

};

// std::ostream & operator<<(std::ostream & o, const Span & rhs);
#endif

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::~MutantStack(){}
