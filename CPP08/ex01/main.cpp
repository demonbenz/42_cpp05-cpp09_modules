#include <iostream>
#include "Span.hpp"
#include <ctime>

void fillSpan(Span &s)
{
    std::srand(time(0));
    unsigned int size = s.getSize();
    for (unsigned int i = 0; i < size ; i++)
        s.addNumber(std::rand() % size);
}

int main(void)
{
    Span sp;
    Span s1(5);
    s1.addNumber(9);
    s1.addNumber(8);
    s1.addNumber(7);
    s1.addNumber(6);
    s1.addNumber(5);
    Span s2(s1);
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    s1.setData(2, 100);
    s2.setData(3, -100);
    std::cout << "s2 getData(3) = " << s2.getData(3) << std::endl;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    Span s3(3);
    std::cout << s3 << std::endl;
    s3 = s2;
    std::cout << s3 << std::endl;
    int sh = s3.shortestSpan();
    std::cout << "shortest span of s3 = " << sh << std::endl;
    std::cout << s3 << std::endl;
    int lp = s1.longestSpan();
    std::cout << "longest span of s1 = " << lp << std::endl;
    std::cout << s1 << std::endl;

    std::cout << " " << std::endl;
    Span s4(100);
    fillSpan(s4);
    std::cout << s4 << std::endl;
    std::cout << "shortest span = " << s4.shortestSpan() << std::endl;
    std::cout << "longest span = " << s4.longestSpan() << std::endl;

    std::cout << " " << std::endl;
    Span s5(10);
    fillSpan(s5);
    std::cout << s5 << std::endl;
    std::cout << "shortest span = " << s5.shortestSpan() << std::endl;
    std::cout << "longest span = " << s5.longestSpan() << std::endl;

//------------------------------------------------------------------------------

    return 0;
}