#ifndef __FORM_HPP__
#define __FORM_HPP__

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
private:
    const std::string _name;
    bool _isSign;
    const int _signGrade;
    const int _execGrade;
public: 
    Form(void);
    Form(std::string name, int signGrade, int execGrade);
    Form(const Form& obj);
    Form& operator= (const Form& obj);
    ~Form(void);

    const std::string& getName(void) const;
    const bool& getIsSign(void) const;
    const int& getSignGrade(void) const;
    const int& getExecGrade(void) const;

    void beSigned(const Bureaucrat& bc);

    class GradeTooHighException : public std::exception {
    public:
        const char* what(void) const throw(); 
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what(void) const throw(); 
    };
};

std::ostream& operator<<(std::ostream& o, const Form& form);

#endif