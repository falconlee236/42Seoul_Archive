#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include <ctime>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& obj);
	~RobotomyRequestForm(void);
	void execute(Bureaucrat const & executor);
};

#endif