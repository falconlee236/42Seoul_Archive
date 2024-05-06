#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void){}
Intern::Intern(const Intern &obj){
    *this = obj;
}

Intern& Intern::operator = (const Intern &obj){
    (void)obj;
    return *this;
}
Intern::~Intern(void){}

AForm* Intern::makeForm(const std::string &name, const std::string &target){
    std::string name_list[3] = { "presidential_form",
                                 "robotomy_form",
                                 "shrubbery_form" };
    AForm *(*f[3])(const std::string &target) = {
        &PresidentialPardonForm::clone, 
        &RobotomyRequestForm::clone, 
        &ShrubberyCreationForm::clone
    };
    
    for(int i = 0; i < 3; i++){
        if (name == name_list[i]){
            std::cout << "Intern creates " << name_list[i] << "\n";
            return f[i](target);
        }
    }
    throw FormNameError();
}

const char* Intern::FormNameError::what() const throw(){
    return "Form name is error..";
}
