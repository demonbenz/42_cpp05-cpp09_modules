#include "RPN.hpp"

// Reverse Polish Notation Calculator(RPN)
RPN::RPN(){}
RPN::~RPN(){}

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
			throw std::out_of_range("data input is not allow.");
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
	if (rpn.empty())
		throw std::runtime_error("invalid data stack notthing left.");
	result = rpn.top();
	rpn.pop();
	if (!rpn.empty())
		throw std::runtime_error("invalid data stack still reamin data.");
	std::cout << result << std::endl;
}

void	RPN::putStack(char c)
{
	switch (c)
	{
		case '0':
			rpn.push(0);
			break;
		case '1':
			rpn.push(1);
			break;
		case '2':
			rpn.push(2);
			break;
		case '3':
			rpn.push(3);
			break;
		case '4':
			rpn.push(4);
			break;
		case '5':
			rpn.push(5);
			break;
		case '6':
			rpn.push(6);
			break;
		case '7':
			rpn.push(7);
			break;
		case '8':
			rpn.push(8);
			break;
		case '9':
			rpn.push(9);
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
			tmp = rpn.top();
			rpn.pop();
			if (rpn.empty())
				throw std::out_of_range(" not thing left in stack.");
			result = tmp + rpn.top();
			rpn.pop();
			rpn.push(result);
			break;
		}
		case '-':
		{
			tmp = rpn.top();
			rpn.pop();
			if (rpn.empty())
				throw std::out_of_range(" not thing left in stack.");
			result = rpn.top() - tmp;
			rpn.pop();
			rpn.push(result);
			break;
		}	
		case '*':
		{
			tmp = rpn.top();
			rpn.pop();
			if (rpn.empty())
				throw std::out_of_range(" not thing left in stack.");
			result = rpn.top() * tmp;
			rpn.pop();
			rpn.push(result);
			break;
		}
		case '/':
		{
			tmp = rpn.top();
			if (tmp == 0)
				throw std::out_of_range(" can not divide by zero.");
			rpn.pop();
			if (rpn.empty())
				throw std::out_of_range(" not thing left in stack.");
			result = rpn.top() / tmp;
			rpn.pop();
			rpn.push(result);
			break;
		}
		default:
			break;
	}
}