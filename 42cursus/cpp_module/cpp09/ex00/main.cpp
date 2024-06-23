#include "BitcoinExchange.hpp"

void print_error(std::string str){
    std::cerr << "Error: " << str << std::endl;
    exit(1);
}

int main(int ac, char **av){
    if (ac != 2)
        print_error("This program needs two arguments");
    
    BitcoinExchange handler(av[1], "data.csv");
    if (!handler.is_valid_file())
        print_error("Cannot open file");
    
    if (!handler.get_stock_data())
        print_error("get stock data failed");
}