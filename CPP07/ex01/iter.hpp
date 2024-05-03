#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void printArray(T elem)
{
	std::cout << " " << elem ;
}
template <typename T>
void addArray(T elem)
{
	elem +=2;
	std::cout << " " << elem ;
}
template <typename T, typename Func>
void iter(T array[],unsigned int len, Func func)
{
	for (unsigned int i = 0; i < len; i++)
		func(array[i]);
}
#endif
