#include "RPN.hpp"

int main(int argc, char *argv[])
{
	RPN	rpn;

	if(argc != 2)
	{
		std::cerr << "Error: .(input arguement != 1)" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			rpn.checkData(argv[1]);
			rpn.calculate(argv[1]);
		}
		catch(std::exception & e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
