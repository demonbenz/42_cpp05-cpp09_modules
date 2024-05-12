#include "RPN.hpp"

// Reverse Polish Notation Calculator(RPN)
RPN::RPN(){}
RPN::~RPN(){}

RPN::RPN(RPN const & rhs)
{
	*this = rhs;
}

RPN & RPN::operator=(RPN const & rhs)
{
	if (this == &rhs)
		return *this;
	this->_rpn = rhs._rpn;
	return *this;
}

void RPN::checkData(const char* argv)
{
	int start = 0;
	while(argv[start] != '\0')
	{
		if(((argv[start] >= '0' )&&(argv[start] <= '9')) || (argv[start] == '+') || (argv[start] == '-') || (argv[start] == '/') || (argv[start] == '*' || (argv[start] == ' ')) )
		{
			//This function allaw only "0 1 2 3 4 5 6 7 8 9 + - * /"
		}
		else
		{
			throw std::out_of_range("<data input is not allow.>");
		}
		++start;
	}
}

void RPN::calculate(const char* argv)
{
	double result = 0;

	std::istringstream iss(argv);
	char c;
	while(iss >> c)
	{
		if ((c != '+') && (c != '-' ) && (c != '*') && (c != '/'))
		{
			//std::cout << "push [" << c << "] in stack" << std::endl;
			putStack(c);
		}
		else
		{
			//std::cout << "operator [" << c << "] " << std::endl;
			popStack(c);
		}	
	}
	if (_rpn.empty())
		throw std::runtime_error("<invalid data stack notthing left.>");
	result = _rpn.top();
	_rpn.pop();
	if (!_rpn.empty())
		throw std::runtime_error("<invalid data stack still reamin data.>");
	std::cout << result << std::endl;
}

void	RPN::putStack(char c)
{
	switch (c)
	{
		case '0':
			_rpn.push(0);
			break;
		case '1':
			_rpn.push(1);
			break;
		case '2':
			_rpn.push(2);
			break;
		case '3':
			_rpn.push(3);
			break;
		case '4':
			_rpn.push(4);
			break;
		case '5':
			_rpn.push(5);
			break;
		case '6':
			_rpn.push(6);
			break;
		case '7':
			_rpn.push(7);
			break;
		case '8':
			_rpn.push(8);
			break;
		case '9':
			_rpn.push(9);
			break;
		default:
			break;
	}
}

void	RPN::popStack(char c)
{
	double tmp = 0;
	double result = 0;
	switch (c)
	{
		case '+':
		{
			tmp = _rpn.top();
			_rpn.pop();
			if (_rpn.empty())
				throw std::out_of_range("<not thing left in stack.>");
			result = tmp + _rpn.top();
			_rpn.pop();
			_rpn.push(result);
			break;
		}
		case '-':
		{
			tmp = _rpn.top();
			_rpn.pop();
			if (_rpn.empty())
				throw std::out_of_range("<not thing left in stack.>");
			result = _rpn.top() - tmp;
			_rpn.pop();
			_rpn.push(result);
			break;
		}	
		case '*':
		{
			tmp = _rpn.top();
			_rpn.pop();
			if (_rpn.empty())
				throw std::out_of_range("<not thing left in stack.>");
			result = _rpn.top() * tmp;
			_rpn.pop();
			_rpn.push(result);
			break;
		}
		case '/':
		{
			tmp = _rpn.top();
			if (tmp == 0)
				throw std::out_of_range("<cant divide by zero.>");
			_rpn.pop();
			if (_rpn.empty())
				throw std::out_of_range("<not thing left in stack.>");
			result = _rpn.top() / tmp;
			_rpn.pop();
			_rpn.push(result);
			break;
		}
		default:
			break;
	}
}

std::stack<int> const & RPN::getStack()const
{
	return this->_rpn;
}

std::ostream & operator<<( std::ostream & o, RPN const & rhs ) {
	o << rhs.getStack();
	return o;
}
std::ostream & operator<<(std::ostream & o, std::stack<int> const & rhs)
{
	std::stack<int> tmp = rhs;
	o << "[";
	while (!tmp.empty())
	{
		o << tmp.top();
		if (tmp.size() != 1)
			o << " , ";
		tmp.pop();
	}
	o << "]";
	return o;
}