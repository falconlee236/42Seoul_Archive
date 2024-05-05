#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat burro("burro", 42);
	std::cout << burro;
	try{
		Form formaccio("formaccio", 1000, 1);
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
	try{
		Form formaccio("formaccio", 42, 0);
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	try{
		Form formino("formino", 42, 42);
		Form formone("formone", 1, 1);

		std::cout << std::endl
				  << formino << formone;

		burro.signForm(formino);
		std::cout << formino;
		burro.signForm(formino);
		std::cout << std::endl;
		burro.signForm(formone);
	}
	catch (std::exception &e){
		std::cout << "Error: " << e.what() << std::endl;
	}
}