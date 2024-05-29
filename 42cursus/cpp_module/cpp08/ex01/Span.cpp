#include "Span.hpp"

Span::Span(void) : _n(0), _v(0){}
Span::Span(unsigned int n) : _n(n), _v(0) {}
Span::Span(const Span &obj) : _n(obj._n), _v(obj._v) {}
Span &Span::operator = (const Span &obj){
    if (this != &obj){
        this->_n = obj._n;
        this->_v = obj._v;
    }
    return *this;
}
Span::~Span(void) {};

void Span::addNumber(int num){
    if (_v.size() == _n)
        throw ArrayFullException();
    _v.push_back(num);
}

unsigned int Span::shortestSpan(void){
    if (_v.size() <= 2)
        throw SpanNotFoundException();
    
    int res = 2147483647;
    std::vector<int> tmp(_v.begin(), _v.end());
    std::sort(tmp.begin(), tmp.end());
    for (unsigned int i = 0; i < _v.size() - 1; i++){
        res = std::min(res, tmp[i + 1] - tmp[i]);
    }
    return res;
}
unsigned int Span::longestSpan(void){
    if (_v.size() <= 2)
        throw SpanNotFoundException();
    
    return *std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end());
}

const char *Span::ArrayFullException::what(void) const throw(){
    return "Array is Full!";
}

const char *Span::SpanNotFoundException::what(void) const throw(){
    return "Span is not found!";
}