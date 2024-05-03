#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template <typename T>
class MutantStack :public std::stack<T>
{
private:
public:
	MutantStack<T>(){}
	~MutantStack<T>(){}
	
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

	MutantStack<T> (const MutantStack<T> & rhs)
	{
		*this = rhs;
	}
	MutantStack<T> & operator=(const MutantStack<T> & rhs)
	{
		if (this != &rhs)
		{
			std::stack<T>::operator=(rhs);
		}
		return (*this);
	}

};

#endif
