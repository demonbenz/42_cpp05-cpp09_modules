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
			pm.printVec(); // print vec before sort
			
			timeVec = pm.sortVec(); // sort data in container vector			
			timeDeque = pm.sortDeque(); // sort data in container Deque

			std::cout << std::endl;
			std::cout << "After:   ";
			pm.printVec(); // print sorted data in container
			
			// print data summary result of sorting
			// std::cout << std::endl;
			// std::cout << "After<Deque>: ";			
			// pm.printDeque(); // print sorted data in container

			//print time summary in 1st container and 2nd container
			std::cout << std::endl;
			std::cout << "Time to process a range of " << num << " elements with std::vector :  ";
			std::cout << std::fixed << std::setprecision(5) << timeVec << " sec" << std::endl;
			std::cout << "Time to process a range of " << num << " elements with std::Deque  :  ";
			std::cout << std::fixed << std::setprecision(5) << timeDeque << " sec" << std::endl;
		}
		catch(std::exception & e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
