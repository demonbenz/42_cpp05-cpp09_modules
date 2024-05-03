#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <exception>

template <typename T>
class Array
{
private:
	T* _elem;
	unsigned int _size;
public:
	Array<T>();
	Array<T>(unsigned int n);
	Array<T>(int n);
	Array<T>(const Array<T>& rhs);
	~Array<T>();
	// memberfunction
	unsigned int get_size(void) const;
	
	// assignment operator	
	T & operator[](unsigned int i);
	Array<T>& operator=(const Array<T>& rhs);
};


template <typename T>
Array<T>::Array(): _size(0)
{
	_elem = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	_elem = new T[n];
}

template <typename T>
Array<T>::Array(int n): _size(n)
{
	if (n < 0)
	{
		throw std::out_of_range("Error: size is must positive number.");
	}
	_elem = new T[n];
}

template <typename T>
Array<T>::Array(const Array<T>& rhs)
{
		this->_size = rhs.get_size();
		this->_elem = new T[rhs.get_size()];
		for (unsigned int i = 0; i < rhs._size; i++)
		{
			this->_elem[i] = rhs._elem[i];
		}	
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Destructor call\n";
	delete [] this->_elem;
	_elem = NULL;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this->get_size() != rhs.get_size())
	{
		throw std::out_of_range("Error: invalid size");
	}
		for (unsigned int i = 0; i < this->get_size(); i++)
		{
			this->_elem[i] = rhs._elem[i];
		}	
	return (*this);
}


template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if(i >= this->_size)
	{
		throw std::out_of_range("Error: index out of range");
	}
	return (this->_elem[i]);
}


template <typename T>
unsigned int Array<T>::get_size(void) const
{
        return (this->_size);
}

#endif