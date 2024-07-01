#include "PmergeMe.hpp"

int main(int ac, char **av){
    if (ac == 1) {
        std::cout << "Invalid Argument\n";
        return 1;
    }
    std::vector<int> arr;
    for(int i = 1; av[i]; i++){
        int num = std::atoi(av[i]);
        if (num <= 0) {
            std::cout << "Invalid value\n";
            return 1;
        }
        arr.push_back(num);
    }

    std::cout << "Before: ";
    for(size_t i = 0 ; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return 0;
}