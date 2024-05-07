#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter(void){}
ScalarConverter::ScalarConverter(const ScalarConverter &obj){
    *this = obj;
}
ScalarConverter& ScalarConverter::operator = (const ScalarConverter &obj){
    (void)obj;
    return *this;
}
ScalarConverter::~ScalarConverter(void){}

void ScalarConverter::convert(std::string &str){
    double res;
    char* end = NULL;
    try{
        // 유효하지 않으면 0.0을 return
        // 근데 진짜 0인 경우를 확인해야함
        res = strtod(str.c_str(), &end);
        if ( res == 0.0 
            && (str[0] != '-' && str[0] != '+' && !std::isdigit(str[0])) // 맨 앞이 -, +, 0으로 시작한 경우
            && (end && std::strcmp(end, "f")) // 맨 위가 f로 끝나는 경우
        ) throw std::bad_cast(); // 위 경우가 아니면 진짜 0이 아닌거임
    } catch (...){
        std::cout << "convert failed" << std::endl;
    }

    // char convert
    std::cout << "char: ";
    if (std::isnan(res) || std::isinf(res)) 
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(res)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "\'" << static_cast<char>(res) << "\'" << std::endl;

    // int convert
    std::cout << "int: ";
    if (std::isnan(res) || std::isinf(res) || res > 2147483647 || res <= -2147483648)
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(res) << std::endl;
    
    // float convert
}