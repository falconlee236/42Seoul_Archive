#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : target_file(""), data_file("") {}
BitcoinExchange::BitcoinExchange(std::string target_name, std::string data_name) : target_file(target_name), data_file(data_name) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj) : target_file(obj.target_file), data_file(obj.data_file) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& obj){
    if (this != &obj){
        this->target_file = obj.target_file;
        this->data_file = obj.data_file;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange(void) {
    target_ifstream.close();
    data_ifstream.close();
}

bool BitcoinExchange::is_valid_file(void) {
    target_ifstream.open(target_file);
    data_ifstream.open(data_file);
    if (target_ifstream.is_open() && data_ifstream.is_open())
        return true;
    else
        return false;
}

bool BitcoinExchange::get_stock_data(void){
    while (!data_ifstream.eof()){
        std::string line; 
        std::getline(data_ifstream, line);
        if (line == "date,exchange_rate")
            continue;

        std::stringstream ss(line);
        std::string token;
        t_date key;
        int idx = 0;
        while (std::getline(ss, token, ',')){
            if (idx == 0){
                key = get_date(token);
                idx++;
            }
            else {
                float f; std::istringstream(token) >> f;
                mp[key] = f;
            }
        }
    }
    return true;
}

t_date BitcoinExchange::get_date(std::string str){
    std::stringstream ss(str);
    std::string token;
    t_date res;
    int cnt = 0;
    while (std::getline(ss, token, '-')){
        if (cnt == 0) res.year = token;
        else if (cnt == 1) res.month = token;
        else res.day = token;
        cnt++;
    }
    return res;
}

std::ostream &operator<<(std::ostream &os, const t_date &date){
    os << date.year << "-" << date.month << "-" << date.day;
    return os;
}

bool operator<(const t_date &lhs, const t_date &rhs){
    if (lhs.year != rhs.year)
        return lhs.year < rhs.year;
    if (lhs.month != rhs.month)
        return lhs.month < rhs.month;
    return lhs.day < rhs.day;
}