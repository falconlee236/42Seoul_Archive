#include "PmergeMe.hpp"

int main(int ac, char **av){
    if (ac == 1) {
        std::cout << "Invalid Argument\n";
        return 1;
    }
    std::vector<int> arr;
    for(int i = 1; av[i]; i++){
        long long num = std::atoll(av[i]);
        if (num <= 0 || num < -2147483648 || num > 2147483647) {
            std::cout << "Invalid value\n";
            return 1;
        }
        int j = 0;
        if (av[i][0] == '+' || av[i][0] == '-') j++;
        while (av[i][j]){
            if (av[i][j] > '9' || av[i][j] < '0'){
                std::cout << "Invalid value\n";
                return 1;
            }
            j++;
        }
        arr.push_back(num);
    }

    std::vector<int> tmp_vec(arr.begin(), arr.end());
    std::deque<int> tmp_deq(arr.begin(), arr.end());

    std::cout << "Before: ";
    for(size_t i = 0 ; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    sorting_use_vector(arr);
    std::cout << "After: ";
    for(size_t i = 0 ; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    clock_t start, end;

    start = clock();
    sorting_use_vector(tmp_vec);
    end = clock();
    print_time(start, end, tmp_vec.size(), "vector");

    start = clock();
    sorting_use_deque(tmp_deq);
    end = clock();
    print_time(start, end, tmp_deq.size(), "deque");
    return 0;
}