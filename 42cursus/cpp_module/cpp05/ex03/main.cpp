#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	Bureaucrat mu = Bureaucrat("mu", 2);
	Intern intern = Intern();

	std::cout << mu;

	try
	{
		AForm *form = intern.makeForm("robotomy_form", "transfomer");
		std::cout << *form;
		mu.signForm(*form);
		std::cout << *form;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern can't make form because " <<  e.what() << "\n\n";
	}

	try
	{
		AForm *form = intern.makeForm("noform", "error");
		std::cout << *form;
		mu.signForm(*form);
		std::cout << *form;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << "Intern can't make form because " << e.what() << "\n\n";
	}
}