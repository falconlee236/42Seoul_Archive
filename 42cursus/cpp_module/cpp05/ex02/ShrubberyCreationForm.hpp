#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm(void);
	void execute(Bureaucrat const & executor);
};

#endif