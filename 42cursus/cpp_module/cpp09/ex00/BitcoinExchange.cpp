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
    if (!data_ifstream.is_open())
        return false;
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
    t_date res;
    std::istringstream yearStream(str.substr(0, 4));
    std::istringstream monthStream(str.substr(5, 2));
    std::istringstream dayStream(str.substr(8, 2));
    yearStream >> res.year;
    monthStream >> res.month;
    dayStream >> res.day;
    return res;
}

bool BitcoinExchange::is_valid_target_file(void){
    if (!target_ifstream.is_open())
        return false;
    int line_cnt = 0;
    while (!target_ifstream.eof()){
        std::string line;
        std::getline(target_ifstream, line);
        if (line_cnt == 0 && line != "date | value")
            return false;
        if (line_cnt == 0 && line == "date | value"){
            line_cnt++;
            continue;
        }
        std::stringstream ss(line);
        std::string token;
        int idx = 0;
        while (std::getline(ss, token, '|')){
            if (idx == 0){
                if (token[token.length() - 1] != ' ' || !isValidDate(token.substr(0, token.length() - 1))){
                    std::cerr << "Error: bad input => " << "\"" << token << "\"" << std::endl;
                    break;
                }
                t_date key = get_date(token.substr(0, token.length() - 1));
                idx++;
                std::cout << key << " ";
            }
            else{
                if (token[0] != ' '){
                    std::cerr << "Error: bad input => " << "\"" << token << "\"" << std::endl;
                    break;
                }
                if (!isValid(token.substr(1))){
                    std::cerr << "Error: not a valid number. => " << "\"" << token << "\"" << std::endl;
                    break;
                }
                float f;
                std::istringstream(token.substr(1)) >> f;
                std::cout << f << "\n";
            }
        }
        line_cnt++;
    }
    return true;
}

bool BitcoinExchange::isFloat(const std::string &str){
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f;       // noskipws considers leading whitespace invalid
    return iss.eof() && !iss.fail(); // Check if it was converted successfully
}

bool BitcoinExchange::isInteger(const std::string &str){
    std::istringstream iss(str);
    int i;
    iss >> std::noskipws >> i;
    return iss.eof() && !iss.fail();
}

bool BitcoinExchange::isValid(const std::string &str){
    if (isFloat(str)){
        std::istringstream iss(str);
        float f;
        iss >> f;
        return f > 0 && f <= 1000;
    }

    if (isInteger(str)){
        std::istringstream iss(str);
        int i;
        iss >> i;
        return i > 0 && i <= 1000;
    }

    return false;
}

bool BitcoinExchange::isLeapYear(int year){
    if (year % 4 != 0)
        return false;
    if (year % 100 == 0 && year % 400 != 0)
        return false;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date){
    // Check the format length
    if (date.length() != 10)
        return false;

    // Check the delimiters
    if (date[4] != '-' || date[7] != '-')
        return false;

    // Extract Year, Month, Day
    int year, month, day;
    std::istringstream yearStream(date.substr(0, 4));
    std::istringstream monthStream(date.substr(5, 2));
    std::istringstream dayStream(date.substr(8, 2));

    if (!(yearStream >> year) || !(monthStream >> month) || !(dayStream >> day)){
        return false;
    }

    // Check ranges
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31){
        return false;
    }

    // Check month lengths
    if (month == 2){
        if (isLeapYear(year)){
            if (day > 29)
                return false;
        }
        else{
            if (day > 28)
                return false;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11){
        if (day > 30)
            return false;
    }
    return true;
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