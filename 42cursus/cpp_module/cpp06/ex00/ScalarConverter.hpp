#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>

class ScalarConverter{
public:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator= (const ScalarConverter &obj);
    ~ScalarConverter();
    static void convert(std::string str);
};
#endif