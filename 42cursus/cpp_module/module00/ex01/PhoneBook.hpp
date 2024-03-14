#include "Contact.hpp"
#include <string>

class PhoneBook{
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    void add_phonebook(void);
    void search_phonebook(void);
};

PhoneBook::PhoneBook(){
    this->index = -1;
}

void PhoneBook::add_phonebook(void){
    std::string f_name, l_name, n_name, p_number, d_secret;
	std::cout << "Enter the first name: "; std::cin >> f_name;
	std::cout << "Enter the last name: "; std::cin >> l_name;
	std::cout << "Enter the nick name: "; std::cin >> n_name;
	std::cout << "Enter the phone number: "; std::cin >> p_number;
	std::cout << "Enter the darkest secret: "; std::cin >> d_secret;
	Contact record = Contact(f_name, l_name, n_name, p_number, d_secret);
    if (record.check_null()){
        std::cout << "Do not leave element blanked\n";
        return;
    }
    contacts[(++index) % 8] = record;
}

void PhoneBook::search_phonebook(void){
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "index";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "first name";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "last name";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "nick name";
    std::cout << " | \n";
    for(int i = 0; i < 8; i++)
        contacts[i].display_contact(std::to_string(i));
    std::string index;
    std::cout << "input need to showing record index: ";
    std::cin >> index;
    try{
        if (std::stoll(index) > 7){
            std::cout << "index out of index\n";
            return;
        }
    }catch(std::invalid_argument){
        std::cout << "invalid argument\n";
        return;
    }
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "index";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "first name";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "last name";
    std::cout << " | ";
    std::cout << std::setw(10) << std::right << "nick name";
    std::cout << " | \n";
    contacts[std::stoll(index)].display_contact(index);
}