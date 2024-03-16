#include <iostream>

int main(void){
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "string variable mem address: " << &str << "\n";
    std::cout << "stringPTR mem address: " << &stringPTR << "\n";
    std::cout << "stringREF mem address: " << &stringREF << "\n";

    std::cout << "string variable value: " << str << "\n";
    std::cout << "stringPTR value: " << *stringPTR << "\n";
    std::cout << "stringREF value: " << stringREF << "\n";
}