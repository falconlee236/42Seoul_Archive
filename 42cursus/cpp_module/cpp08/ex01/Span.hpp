#ifndef __SPAN_HPP__
#define __SPAN_HPP__

class Span{
private:
    unsigned int _n;
public:
    Span(void);
    Span(unsigned int n);
    Span(const Span& obj);
    Span& operator= (const Span& obj);
    ~Span(void);

    void addNumber();
    shortestSpan();
    longestSpan();
};

#endif