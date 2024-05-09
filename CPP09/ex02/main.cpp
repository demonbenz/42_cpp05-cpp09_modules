#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	PmergeMe pm;
	double 	timeVec = 0;
	double 	timeList = 0;
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
			std::cout << "Before: ";
			int i = 1;
			while(i < argc)
			{
				pm.checkAndInput(argv[i]);
				std::cout << argv[i] << " ";
				i++;
				num++;
			}			
			timeVec = pm.sortVec(); // sort data in container vector			
			timeList = pm.sortList(); // sort data in container list
			// print data summary result of sorting
			std::cout << std::endl;
			std::cout << "After<list>: ";			
			pm.printList(); // print sorted data in container
			std::cout << std::endl;
			std::cout << "After<Vec>: ";
			pm.printVec(); // print sorted data in container
			// print time summary in 1st conatiner
			std::cout << std::endl;
			std::cout << "Time to process a range of " << num << " elements with std::vector : ";
			std::cout << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
			// print time summary in 2nd conatiner
			std::cout << "Time to process a range of " << num << " elements with std::list : ";
			std::cout << std::fixed << std::setprecision(5) << timeList << " us" << std::endl;
		}
		catch(std::exception & e)
		{
			std::cout << "Error: " << e.what() << std::endl;
			return (1);
		}
	}
	return 0;
}
