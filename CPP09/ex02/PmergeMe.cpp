#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}

void  PmergeMe::checkAndInput(const char * str)
{
	long long num;
	std::istringstream iss(str);
	iss >> num;

	if (num < 0)
		throw std::out_of_range("not negative number.");
	else if (num > INT_MAX)
		throw std::out_of_range("number out of range.");
	else{
		while(*str)
		{
			if (!isdigit(*str) && *str != ' ')
				throw std::out_of_range("not number because contain alphabet.");
			++str;
		}
	}
	putDataToDeque(num);
	putDataToVec(num);
}

void	PmergeMe::putDataToDeque(long long num)
{
	_pmDeque.push_back(static_cast<unsigned int>(num));
}

void	PmergeMe::putDataToVec(long long num)
{
	_pmVec.push_back(static_cast<unsigned int>(num));
}

void	PmergeMe::printDeque()
{
	std::deque<unsigned int>::iterator it = _pmDeque.begin();
	for (;it != _pmDeque.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

void	PmergeMe::printVec()
{
	std::vector<unsigned int>::iterator it = _pmVec.begin();
	for (;it != _pmVec.end(); ++it)
	{
		std::cout << *it << " ";
	}
}

double	PmergeMe::sortVec()
{
	clock_t startTime = clock();

	//std::sort(_pmVec.begin(), _pmVec.end());// This isinsertion sort.
	mergeInsertSortVec(_pmVec);
	clock_t endTime = clock();
	double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

	return (totalTime);
}

double	PmergeMe::sortDeque()
{
	clock_t startTime = clock();

	//std::sort(_pmDeque.begin(), _pmDeque.end()); // this is insertion sort
	mergeInsertSortDeque(_pmDeque);
	clock_t endTime = clock();
	double totalTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC;

	return (totalTime);
}

// Deque

void	PmergeMe::mergeInsertSortDeque(std::deque<unsigned int> & arr)
{
	int size = arr.size();
	std::deque<unsigned int>temp(size);
	mergeISSortHelpDeque(arr , temp, 0, size - 1);
}

void	PmergeMe::mergeISSortHelpDeque(std::deque<unsigned int> & arr, std::deque<unsigned int> & temp , int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if ((right - left + 1) <= 5)
	{
		// this line is use insertion sort if data is <= 5
		std::sort(arr.begin() + left, arr.begin() + right + 1);
		return;
	}
	int mid = (left + right) / 2;
	mergeISSortHelpDeque(arr, temp, left, mid);
	mergeISSortHelpDeque(arr, temp, mid + 1, right);
	mergeDeque(arr, temp, left, mid, right);
}

void	PmergeMe::mergeDeque(std::deque<unsigned int> & arr,std::deque<unsigned int> & temp, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
	{
        if (arr[i] <= arr[j])
		{
            temp[k++] = arr[i++];
        }
		else
		{
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
	{
        temp[k++] = arr[i++];
    }
    while (j <= right)
	{
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; ++i)
	{
        arr[left + i] = temp[i];
    }
}

// Vector

void	PmergeMe::mergeInsertSortVec(std::vector<unsigned int> & arr)
{

	int size = arr.size();
	std::vector<unsigned int>temp(size);
	mergeISSortHelpVec(arr , temp, 0, size - 1);
}

void	PmergeMe::mergeISSortHelpVec(std::vector<unsigned int> & arr, std::vector<unsigned int> & temp , int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if ((right - left + 1) <= 5)
	{
		// this line is use insertion sort if data is <= 5
		std::sort(arr.begin() + left, arr.begin() + right + 1);
		return;
	}
	int mid = (left + right) / 2;
	mergeISSortHelpVec(arr, temp, left, mid);
	mergeISSortHelpVec(arr, temp, mid + 1, right);
	mergeVec(arr, temp, left, mid, right);
}

void	PmergeMe::mergeVec(std::vector<unsigned int> & arr,std::vector<unsigned int> & temp, int left, int mid, int right)
{
	int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
	{
        if (arr[i] <= arr[j])
		{
            temp[k++] = arr[i++];
        }
		else
		{
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
	{
        temp[k++] = arr[i++];
    }
    while (j <= right)
	{
        temp[k++] = arr[j++];
    }
    for (i = 0; i < k; ++i)
	{
        arr[left + i] = temp[i];
    }
}