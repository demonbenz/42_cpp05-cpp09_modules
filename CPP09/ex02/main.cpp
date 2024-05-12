#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe pm;
	double 	timeVec = 0;
	double 	timeDeque = 0;
	unsigned int num = 0;

	if(argc <= 2)
	{
		std::cerr << "Error: .(cant sort because argument < 2)" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			int i = 1;
			while(i < argc)
			{
				pm.checkAndInput(argv[i]);
				i++;
				num++;
			}

			std::cout << "Before:  ";
			std::cout << pm.getVec();
			timeVec = pm.sortVec();		
			timeDeque = pm.sortDeque();
			std::cout << std::endl;		
			std::cout << "After:   ";			
			std::cout << pm.getVec();
			// pm.printVec();
			// pm.printDeque();

			//print time summary in 1st container and 2nd container
			std::cout << std::endl;
			std::cout << "Time to process a range of " << num << " elements with std::vector :  ";
			std::cout << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
			std::cout << "Time to process a range of " << num << " elements with std::Deque  :  ";
			std::cout << std::fixed << std::setprecision(5) << timeDeque << " us" << std::endl;
		}
		catch(std::exception & e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
