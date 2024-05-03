#include "easyfind.hpp"

template <typename T>
void fillContainer(T & container, int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; ++i)
    {
        container.push_back(arr[i]);
    }
}

template <typename T>
void printContainer(T &container)
{
    std::cout << "[";
    typename T::iterator it = container.begin();
    for (; it != container.end(); ++it)
    {
        if (it == container.begin()){}
        else 
            std::cout << ", ";
        std::cout << *it;
    }
    std::cout << "]" << std::endl;
}

int main(void)
{
    
    std::cout << "\n\n-vector- \n";
    std::vector<int> vInt;
    int arr[6] = {1,2,4,16,11,15};
    fillContainer(vInt, arr, 6);
    printContainer(vInt);
    if (easyfind(vInt, 4) == 1)
        std::cout << "find";
    else
        std::cout << "not found";
 
    
    std::cout << "\n\n-list- \n";
    int brr[10] = {1,3,5,7,9,11, 13,15,17,19};
    std::list<int> lInt;
    fillContainer(lInt, brr, 10);
    printContainer(lInt);
    if (easyfind(lInt, 19) == 1)
        std::cout << "find";
    else
        std::cout << "not found";

    
    std::cout << "\n\n-deque- \n";
    int crr[15] = {2,4,6,8,10,12,14,16,18,20, 22,24,26,28,30};
    std::deque<int> dInt;
    fillContainer(dInt, crr, 15);
    printContainer(dInt);
    if (easyfind(dInt, 30) == 1)
        std::cout << "find";
    else
        std::cout << "not found";

    std::cout << "\n\n-set- \n";
    std::deque<int> setInt;
    int srr[15] = {0,-20,45,42,10,42,2,0,1,200, 2,4,6,8,3};
    fillContainer(setInt, srr, 15);
    printContainer(setInt);
    if (easyfind(setInt, 42) == 1)
        std::cout << "find";
    else
        std::cout << "not found";

//    std::cout << "\n\n -vector- \n\n";
    
//     std::vector<int> vInt;
//     vInt.push_back(1);
//     vInt.push_back(2);
//     vInt.push_back(4);
//     vInt.push_back(16);
//     vInt.push_back(11);
//     vInt.push_back(15);
//     try{
//         std::cout << easyfind(vInt, 15) << std::endl;
//     }
//     catch(std::exception & e)
//     {
//         std::cout << "Error : " << e.what() << std::endl;
//     }

    return 0;
}
