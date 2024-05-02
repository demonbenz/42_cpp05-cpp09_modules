#include "MutantStack.hpp"


int main(void)
{
    // std::stack<int> a;
    // MutantStack<int> b;
    // a.push(22);
    // a.push(24);
    // a.push(25);
   
    // b.push(12);
    // b.push(14);
    // b.push(15);
    
    // while (!a.empty()) 
    // {
    //     std::cout << a.top() <<" ";
    //     a.pop();
    // }
    // std::cout << std::endl;
    // while (!b.empty()) 
    // {
    //     std::cout << b.top() <<" ";
    //     b.pop();
    // }

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

    // std::cout << s.top() << std::endl;
    return 0;
}