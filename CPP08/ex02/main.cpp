#include "MutantStack.hpp"

int main(void)
{

//MutantStack-----------------------------------------------------------------------------

    MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
 //[...]
         mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;--it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);



//List-----------------------------------------------------------------------------

//         std::list<int> lst;
//         lst.push_back(5);
//         lst.push_back(17);
//         std::cout << lst.back() << std::endl;
//         lst.remove(lst.back());
//         std::cout << lst.size() << std::endl;
//         lst.push_back(3);
//         lst.push_back(5);
//         lst.push_back(737);
//  //[...]
//         lst.push_back(0);
//     std::list<int>::iterator it = lst.begin();
//     std::list<int>::iterator ite = lst.end();
//     ++it;--it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::list<int> s(lst);

//-----------------------------------------------------------------------------

    // std::stack<int> a;
    // MutantStack<int> b;
    // a.push(22);
    // a.push(24);
    // a.push(25);
   
    // b.push(12);
    // b.push(14);
    // b.push(15);

    // std::cout << "Stack       a: ";
    // while (!a.empty()) 
    // {
    //     std::cout << a.top() <<" ";
    //     a.pop();
    // }
    // std::cout << std::endl;
    // std::cout << "MutantStack b: ";
    // while (!b.empty()) 
    // {
    //     std::cout << b.top() <<" ";
    //     b.pop();
    // }


    return 0;
}