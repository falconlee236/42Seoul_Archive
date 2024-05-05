#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat mu = Bureaucrat("mu", 2);
		std::cout << mu;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		Bureaucrat samsak = Bureaucrat("samsak", 153);
		std::cout << samsak;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	Bureaucrat mu("mu", 1);
	Bureaucrat samsak("samsak", 150);

	try {
		mu.increment();
		std::cout << mu;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		samsak.decrement();
		std::cout << samsak;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		mu.decrement();
		std::cout << mu;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		samsak.increment();
		std::cout << samsak;
	} catch (std::exception& e) {
		std::cerr << e.what() << "\n\n";
	}
}