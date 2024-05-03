
#include "iter.hpp"
#include <iostream>


int	main(void)
{
	int ar01[8] = {-1,-2,-3,-4,-5,-6,-7,-8};
	unsigned int ar02[8] = {1,2,3,4,5,6,7,8};

	std::cout << "Hello iter" << std::endl;

	iter(ar01, 8, printArray<int>);
	std::cout << std::endl;
	iter(ar01, 8, addArray<int>);

	std::cout << std::endl;
	iter(ar02, 8, printArray<int>);
	std::cout << std::endl;
	iter(ar02, 8, addArray<int>);
	std::cout << std::endl;
	return (0);
}
