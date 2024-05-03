#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <algorithm>
#include <exception>

template<typename T>
bool easyfind(const T & container, int value)
{
	if( std::find(container.begin(),container.end(), value) == container.end())
	{
		return false;
	}
	return true;
}

// template<typename T>
// int easyfind(const T & container, int value)
// {
// 	int index = 0;
// 	typename T::iterator it = container.begin();
// 	for(;it != container.end(); ++it)
// 	{
// 		if (*it == value)
// 			return index;
// 		index++;
// 	}
// 	throw std::out_of_range("Can not find.");
// }

#endif
