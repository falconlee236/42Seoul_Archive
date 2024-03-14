#include "PhoneBook.hpp"

int main(void){
	PhoneBook phoneBook = PhoneBook();
	while(true){
		std::cout << "Enter the ADD, SEARCH, EXIT command, other is ignored: ";
		std::string cmd; std::cin >> cmd;
		if (cmd == "ADD"){
			std::string f_name, l_name, n_name, p_number, d_secret;
			std::cout << "Enter the first name: "; std::cin >> f_name;
			std::cout << "Enter the last name: "; std::cin >> l_name;
			std::cout << "Enter the nick name: "; std::cin >> n_name;
			std::cout << "Enter the phone number: "; std::cin >> p_number;
			std::cout << "Enter the darkest secret: "; std::cin >> d_secret;
			Contact record = Contact(f_name, l_name, n_name, p_number, d_secret);
			phoneBook.add_phonebook(record);
			phoneBook.search_phonebook();
		}
		// else if (cmd == "SEARCH")
		// else if (cmd == "EXIT")
		// 	break;
	}
	return 0;
}