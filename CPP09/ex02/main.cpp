#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe pm;
	if(argc <= 2)
	{
		std::cerr << "Error: .(cant sort because argument < 2)" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			std::cout << "Before: ";
			int i = 1;
			while(i < argc)
			{
				pm.checkAndInput(argv[i]);
				std::cout << argv[i] << " ";
				i++;
			}
		}
		catch(std::exception & e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
