#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(75){}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (this->_grade < 1)
		throw GradeTooHighException();
	if (this->_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : _name(obj.getName()), _grade(obj.getGrade()) {}

Bureaucrat& Bureaucrat::operator= (const Bureaucrat& obj){
	if (this != &obj){
		*(const_cast<std::string*>(&_name)) = obj.getName();
		this->_grade = obj.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(void){}

const std::string& Bureaucrat::getName(void) const {
	return this->_name;
}

const int& Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void Bureaucrat::increment(void){
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::decrement(void){
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw(){
	return "Grade Too High...\n";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
	return "Grade Too Low...\n";
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& obj){
	return o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n"; 
}