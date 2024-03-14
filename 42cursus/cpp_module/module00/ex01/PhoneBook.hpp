#include "Contact.hpp"
#include <string>

class PhoneBook{
private:
    Contact contacts[8];
    int index;
public:
    PhoneBook();
    void add_phonebook(Contact record);
    void search_phonebook(void);
};

PhoneBook::PhoneBook(){
    this->index = -1;
}

void PhoneBook::add_phonebook(Contact record){
    contacts[(++index) % 8] = record;
}

void PhoneBook::search_phonebook(void){
    contacts[index].display_contact(std::to_string(index));
}