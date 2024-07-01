#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <map>

typedef struct s_date{
    int year;
    int month;
    int day;
} t_date;

std::ostream &operator<<(std::ostream &os, const t_date &date);
bool operator<(const t_date &lhs, const t_date &rhs);

class BitcoinExchange{
private:
    std::string target_file, data_file;
    std::ifstream target_ifstream, data_ifstream;
    std::map<t_date, float> mp;

    t_date get_date(std::string str);
    bool isFloat(const std::string &str);
    bool isInteger(const std::string &str);
    bool isValid(const std::string &str);
    bool isLeapYear(int year);
    bool isValidDate(const std::string &date);
public: 
    BitcoinExchange(void);
    BitcoinExchange(std::string target_name, std::string data_name);
    BitcoinExchange(const BitcoinExchange &obj);
    BitcoinExchange &operator=(const BitcoinExchange& obj);
    ~BitcoinExchange(void);

    bool is_valid_file(void);
    bool get_stock_data(void);
    bool is_valid_target_file(void);
};
#endif