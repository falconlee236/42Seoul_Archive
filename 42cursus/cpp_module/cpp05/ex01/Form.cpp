#include "Form.hpp"

Form::Form(void) : _name("default"), _signGrade(75), _execGrade(75) {
    this->_isSign = false;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade){
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw GradeTooHighException();
    if (this->_signGrade > 150 || this->_signGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &obj) : _name(obj.getName()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade()) {
    this->_isSign = obj.getIsSign();
}

Form &Form::operator=(const Form &obj){
    if (this != &obj){
        *(const_cast<std::string *>(&_name)) = obj.getName();
        *(const_cast<int *>(&_signGrade)) = obj.getSignGrade();
        *(const_cast<int *>(&_execGrade)) = obj.getExecGrade();
        this->_isSign = obj.getIsSign();
    }
    return *this;
}

Form::~Form(void) {}

const std::string &Form::getName(void) const{return this->_name;}
const bool& Form::getIsSign(void) const{return this->_isSign;}
const int& Form::getSignGrade(void) const{return this->_signGrade;}
const int& Form::getExecGrade(void) const{return this->_execGrade;}


void Form::beSigned(const Bureaucrat& bc){
    if (this->getSignGrade() >= bc.getGrade())
        this->_isSign = true;
    else{
        this->_isSign = false;
        throw GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what(void) const throw(){
    return "Grade Too High...";
}

const char *Form::GradeTooLowException::what(void) const throw(){
    return "Grade Too Low...";
}

std::ostream &operator<<(std::ostream &o, const Form &obj){
    return o << obj.getName() << std::boolalpha << ", form signed " << obj.getIsSign() << ", sign grade " << obj.getSignGrade() << ", exec grade " << obj.getExecGrade() << ".\n";
}