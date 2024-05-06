#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm& operator= (const PresidentialPardonForm& obj);
	~PresidentialPardonForm(void);
	void execute(Bureaucrat const & executor);
	static AForm *clone(const std::string &target);
};

#endif