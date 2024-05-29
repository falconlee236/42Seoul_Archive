#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

class Span{
private:
    unsigned int _n;
    std::vector<int> _v;
public:
    Span(void);
    Span(unsigned int n);
    Span(const Span& obj);
    Span& operator= (const Span& obj);
    ~Span(void);

    void addNumber(int num);

    template <typename T>
    void addNumbers(T &container){
        if (this->_v.size() + container.size() > this->_n)
            throw ArrayFullException();
        for (typename T::iterator it = container.begin(); it != container.end(); it++)
            this->_v.push_back(*it);
    }

    unsigned int shortestSpan(void);
    unsigned int longestSpan(void);

    class ArrayFullException : public std::exception {
        public:
            const char* what(void) const throw();
    };

    class SpanNotFoundException : public std::exception{
    public:
        const char *what(void) const throw();
    };
};

#endif