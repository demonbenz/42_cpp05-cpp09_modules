#include "Span.hpp"

Span::Span(): _maxSize(0){}
Span::Span(unsigned int N): _maxSize(N){}
Span::~Span(){}
Span::Span (const Span& rhs)
{
	this->_maxSize = rhs._maxSize;
	this->_data = rhs._data;
}

Span & Span::operator=(const Span & rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_data = rhs._data;
	}
	return (*this);
}

void Span::addNumber(const int num)
{
	if(this->_data.size() >= this->_maxSize)
		throw std::out_of_range("Size is full.");
	this->_data.push_back(num);
}
int Span::shortestSpan()
{
	int sp;
	
	if (this->_maxSize < 2)
	{
		throw std::range_error("range is error.");
	}
	std::sort(_data.begin(),_data.end());	
	std::vector<int>::const_iterator it = this->_data.begin();
	std::vector<int>::const_iterator next = it + 1;
	sp = *next - *it;
	while(it != _data.end() && next != _data.end())
	{
		if((*next - *it) < sp)
		{
			sp = (*next - *it);
		}
		it++;
		next++;
	}
	return sp;
}
int Span::longestSpan()
{
	int lp;
	if (this->_maxSize < 2)
	{
		throw std::range_error("range is error.");
	}
	std::vector<int>::iterator max = std::max_element(this->_data.begin(), this->_data.end());
	std::vector<int>::iterator min = std::min_element(this->_data.begin(), this->_data.end());
	lp = *max - *min;
	return lp;
}
std::string Span::toString() const
{
	std::vector<int>::const_iterator it;
	std::stringstream s;
	std::string outStr;
	outStr = "[";
	for (it = _data.begin(); it != _data.end(); it++)
	{
		if (it != _data.begin())
			outStr.append(", ");
		outStr += " ";
		s << (*it);
		outStr += s.str();
		s.str("");
	}
	outStr.append("]");
	return outStr;
}

std::ostream & operator<<(std::ostream & o, const Span & rhs)
{
	o << rhs.toString();
	return o;
}

void Span::setData(const unsigned int index, int value)
{
	if (index >= _maxSize)
		throw std::out_of_range("out of range.");
	this->_data[index] = value;
}

int Span::getData(const unsigned int index)
{
	if (index >= _maxSize)
		throw std::out_of_range("out of range.");
	return this->_data.at(index);
}

unsigned int Span::getSize()
{
	return this->_maxSize;
}


Span & Span::fillSpan()
{
    std::srand(time(0));
    unsigned int size = this->getSize();
    for (unsigned int i = 0; i < size ; i++)
        this->addNumber(std::rand() % size);
		return(*this);
}