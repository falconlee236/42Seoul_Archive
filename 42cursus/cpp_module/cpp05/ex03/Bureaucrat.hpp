#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator= (const Bureaucrat& obj);
	~Bureaucrat(void);

	const std::string& getName(void) const;
	const int& getGrade(void) const;

	void increment(void);
	void decrement(void);

	void signForm(AForm& form);
	void executeForm(AForm const &form);
	
	class GradeTooHighException : public std::exception{
	public:
		const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception{
	public:
		const char* what(void) const throw();
	};

};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj);
#endif