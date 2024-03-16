#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"
#include <string>
#include <sstream>

class PhoneBook{
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    void add_phonebook(void);
    void search_phonebook(void);
};


void print_header(bool flag){
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "index";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "first name";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "last name";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "nick name";
    if (flag){
        std::cout << " | ";
        std::cout << std::setw(10) << std::right << "p_number";
        std::cout << " | ";
        std::cout << std::setw(10) << std::right << "d_secret";
    }
    std::cout << " | \n";
}
PhoneBook::PhoneBook(){
    this->index = -1;
}

void PhoneBook::add_phonebook(void){
    std::string f_name, l_name, n_name, p_number, d_secret;
	std::cout << "Enter the first name: "; std::getline(std::cin, f_name);
	std::cout << "Enter the last name: "; std::getline(std::cin, l_name);
	std::cout << "Enter the nick name: "; std::getline(std::cin, n_name);
	std::cout << "Enter the phone number: "; std::getline(std::cin, p_number);
	std::cout << "Enter the darkest secret: "; std::getline(std::cin, d_secret);
	Contact record = Contact(f_name, l_name, n_name, p_number, d_secret);
    if (record.check_null()){
        std::cout << "Do not leave element blanked\n";
        return;
    }
    contacts[(++index) % 8] = record;
}

void PhoneBook::search_phonebook(void){
    print_header(false);
    std::stringstream ss;
    for(int i = 0; i < 8; i++){
        std::string num_str;
        ss << i;
        ss >> num_str;
        ss.str(""); // clear the stringstream
        ss.clear(); // clear the state flags for another conversion
        contacts[i].display_contact(num_str);
    }
    std::string index;
    std::cout << "input need to showing record index: ";
    std::cin >> index;
    int num_index;
    ss << index;
    ss >> num_index;
    ss.str(""); ss.clear();
    std::string num_index_string;
    ss << num_index;
    ss >> num_index_string;
    ss.str(""); ss.clear();
    if (num_index > 7 || num_index < 0 
        || index.find(".") != std::string::npos 
        || (num_index == 0 && index[0] != '0')
        || num_index_string.length() != index.length()){
        std::cout << "invalid argument\n";
        return;
    }
    print_header(true);
    ss << index;
    ss >> num_index;
    ss.str(""); ss.clear();
    contacts[num_index].display_record(index);
}
#endif