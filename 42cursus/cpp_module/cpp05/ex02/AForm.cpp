#include "AForm.hpp"

AForm::AForm(void) : _name("default"), _signGrade(75), _execGrade(75) {
    this->_isSign = false;
}

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade){
    this->_isSign = false;
    if (this->_signGrade < 1 || this->_execGrade < 1)
        throw GradeTooHighException();
    if (this->_signGrade > 150 || this->_signGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade()) {
    this->_isSign = obj.getIsSign();
}

AForm &AForm::operator=(const AForm &obj){
    if (this != &obj){
        *(const_cast<std::string *>(&_name)) = obj.getName();
        *(const_cast<int *>(&_signGrade)) = obj.getSignGrade();
        *(const_cast<int *>(&_execGrade)) = obj.getExecGrade();
        this->_isSign = obj.getIsSign();
    }
    return *this;
}

AForm::~AForm(void) {}

const std::string &AForm::getName(void) const{return this->_name;}
const bool& AForm::getIsSign(void) const{return this->_isSign;}
const int& AForm::getSignGrade(void) const{return this->_signGrade;}
const int& AForm::getExecGrade(void) const{return this->_execGrade;}


void AForm::beSigned(const Bureaucrat& bc){
    if (this->getSignGrade() >= bc.getGrade())
        this->_isSign = true;
    else{
        this->_isSign = false;
        throw GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what(void) const throw(){
    return "Grade Too High...";
}

const char *AForm::GradeTooLowException::what(void) const throw(){
    return "Grade Too Low...";
}

const char *AForm::NotSignedException::what(void) const throw(){
    return "Form is not signed...";
}

const char *AForm::NotExecuteException::what(void) const throw(){
    return "Cannot Execute...";
}

std::ostream &operator<<(std::ostream &o, const AForm &obj){
    return o << obj.getName() << std::boolalpha << ", form signed " << obj.getIsSign() << ", sign grade " << obj.getSignGrade() << ", exec grade " << obj.getExecGrade() << ".\n";
}