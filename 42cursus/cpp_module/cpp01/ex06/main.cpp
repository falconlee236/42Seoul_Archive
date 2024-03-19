#include "Harl.hpp"

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "This program need to one parameter\n";
        return 0;
    }
    Harl harl = Harl();
    harl.complain(av[1]);
    return 0;
}