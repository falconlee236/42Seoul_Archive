#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <iomanip>
#include <cstdlib>

class ScalarConverter{
private:
    ScalarConverter(void);
public:
    ScalarConverter(const ScalarConverter& obj);
    ScalarConverter& operator= (const ScalarConverter &obj);
    ~ScalarConverter(void);
    static void convert(const std::string &str);
};
#endif