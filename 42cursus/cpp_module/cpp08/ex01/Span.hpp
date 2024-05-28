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
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

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