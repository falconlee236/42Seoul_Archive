#include "Span.hpp"

Span::Span(void) : _n(0), _v(0){}
Span::Span(unsigned int n) : _n(n), _v(n) {}
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
unsigned int Span::shortestSpan() const{
    if (_v.size() <= 1)
        throw SpanNotFoundException();
    
    size_t mid = _v.size() / 2;
    std::sort(_v.begin(), _v.end());
    if (mid & 1){
        return _v[mid] - _v[mid - 1] > _v[mid + 1] - _v[mid] ? _v[mid + 1] - _v[mid] : _v[mid] - _v[mid - 1];
    } else {
        return _v[mid] - _v[mid - 1];
    }
}
unsigned int Span::longestSpan() const{
    if (_v.size() <= 1)
        throw SpanNotFoundException();
    
    unsigned int res = 0;
    int max_element = *(std::max_element(_v.begin(), _v.end()));
    int min_element = *(std::max_element(_v.begin(), _v.end()));
    return max_element - min_element;
}

const char *Span::ArrayFullException::what(void) const throw(){
    return "Array is Full!";
}

const char *Span::SpanNotFoundException::what(void) const throw(){
    return "Span is not found!";
}