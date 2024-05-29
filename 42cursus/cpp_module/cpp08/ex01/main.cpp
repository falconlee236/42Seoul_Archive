#include "Span.hpp"

int main(){
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try{
        sp.addNumber(9);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span new_sp = Span(5);
    std::vector<int> test;
    for(int i = 0; i < 10; i += 2)
        test.push_back(i);
    try{
        new_sp.addNumbers(test);
        std::cout << new_sp.shortestSpan() << std::endl;
        std::cout << new_sp.longestSpan() << std::endl;
    } catch (const std::exception &e){
        std::cerr << "Error : " << e.what() << std::endl;
    }
    return 0;
}