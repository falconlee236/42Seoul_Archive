#include "RPN.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "Invalid arguments\n";
        return 1;
    }
    if (!cal(std::string(av[1]))){
        std::cout << "Error\n";
    }
    return 0;
}