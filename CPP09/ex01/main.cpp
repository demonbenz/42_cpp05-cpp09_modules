#include "RPN.hpp"

int main(int argc, char *argv[])
{
	RPN	rpnObj;

	if(argc != 2)
	{
		std::cerr << "Error: .(input arguement != 1)" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			rpnObj.checkData(argv[1]);
			rpnObj.calculate(argv[1]);
		}
		catch(std::exception & e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
