#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define BUREAUCRAT "\033[1;30m"
# define SHRUBBERY "\033[1;32m"
# define ROBOT "\033[1;36m"
# define PARDON "\033[1;35m"

int main() {
	Bureaucrat mu = Bureaucrat("mu", 2);
	Bureaucrat samsak = Bureaucrat("samsak", 139);
	Bureaucrat yatong = Bureaucrat("yatong", 148);
	AForm* moon = new ShrubberyCreationForm("Moon");

	std::cout << BUREAUCRAT << mu << std::endl;
	std::cout << BUREAUCRAT << samsak << std::endl;
	std::cout << BUREAUCRAT << yatong << std::endl;
	std::cout << SHRUBBERY << *moon << std::endl;
	mu.signForm(*moon);
	std::cout << SHRUBBERY << *moon << std::endl;
	mu.executeForm(*moon);
	samsak.signForm(*moon);
	std::cout << SHRUBBERY << *moon << std::endl;
	samsak.executeForm(*moon);
	yatong.signForm(*moon);
	std::cout << SHRUBBERY << *moon << std::endl;
	yatong.executeForm(*moon);
	delete moon;

	AForm* robot = new RobotomyRequestForm("transfomer");
	std::cout << ROBOT << *robot << std::endl;
	mu.signForm(*robot);
	mu.executeForm(*robot);

	AForm* where42 = new PresidentialPardonForm("where42");
	std::cout << PARDON << *where42 << std::endl;
	mu.signForm(*where42);
	mu.executeForm(*where42);
	delete where42;
}