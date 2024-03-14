#include "PhoneBook.hpp"

int main(void){
	PhoneBook phoneBook = PhoneBook();
	while(true){
		std::cout << "Enter the ADD, SEARCH, EXIT command, other is ignored: ";
		std::string cmd; std::cin >> cmd;
		if (cmd == "ADD")
			phoneBook.add_phonebook();
		else if (cmd == "SEARCH")
			phoneBook.search_phonebook();
		else if (cmd == "EXIT")
			return 0;
	}
}