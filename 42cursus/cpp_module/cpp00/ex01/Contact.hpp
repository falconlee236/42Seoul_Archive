#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <iostream>
#include <iomanip>

class Contact{
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;
public:
    Contact();
    Contact(
        std::string first_name,
        std::string last_name,
        std::string nick_name,
        std::string phone_number,
        std::string darkest_secret);
    void display_contact(std::string index);
    void display_record(std::string index);
    bool check_null(void);
};

Contact::Contact(){
    this->first_name = "";
    this->last_name = "";
    this->nick_name = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::Contact(
    std::string first_name, std::string last_name, std::string nick_name,
    std::string phone_number, std::string darkest_secret){
    this->first_name = first_name;
    this->last_name = last_name;
    this->nick_name = nick_name;
    this->phone_number = phone_number;
    this->darkest_secret = darkest_secret;
}

bool Contact::check_null(void){
    if (this->first_name == "" || this->last_name == "" || this->nick_name == "" ||
        this->phone_number == "" || this->darkest_secret == "")
        return true;
    return false;
}

void Contact::display_contact(std::string index){
    std::cout << " | ";
    if (index.length() > 10)
        std::cout << std::setw(10) << std::right << index.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << index;
    std::cout << " | ";
    if (this->first_name.length() > 10)
        std::cout << std::setw(10) << std::right << this->first_name.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->first_name;
    std::cout << " | ";
    if (this->last_name.length() > 10)
        std::cout << std::setw(10) << std::right << this->last_name.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->last_name;
    std::cout << " | ";
    if (this->nick_name.length() > 10)
        std::cout << std::setw(10) << std::right << this->nick_name.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->nick_name;
    std::cout << " | ";
    std::cout << "\n";
}

void Contact::display_record(std::string index){
    std::cout << " | ";
    if (index.length() > 10)
        std::cout << std::setw(10) << std::right << index.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << index;
    std::cout << " | ";
    if (this->first_name.length() > 10)
        std::cout << std::setw(10) << std::right << this->first_name.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->first_name;
    std::cout << " | ";
    if (this->last_name.length() > 10)
        std::cout << std::setw(10) << std::right << this->last_name.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->last_name;
    std::cout << " | ";
    if (this->nick_name.length() > 10)
        std::cout << std::setw(10) << std::right << this->nick_name.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->nick_name;
    std::cout << " | ";
    if (this->phone_number.length() > 10)
        std::cout << std::setw(10) << std::right << this->phone_number.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->phone_number;
    std::cout << " | ";
    if (this->darkest_secret.length() > 10)
        std::cout << std::setw(10) << std::right << this->darkest_secret.substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << std::right << this->darkest_secret;
    std::cout << " | ";
    std::cout << "\n";
}
#endif