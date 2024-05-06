#ifndef __AFORM_HPP__
#define __AFORM_HPP__

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
private:
    const std::string _name;
    bool _isSign;
    const int _signGrade;
    const int _execGrade;
public: 
    AForm(void);
    AForm(std::string name, int signGrade, int execGrade);
    AForm(const AForm& obj);
    AForm& operator= (const AForm& obj);
    ~AForm(void);

    const std::string& getName(void) const;
    const bool& getIsSign(void) const;
    const int& getSignGrade(void) const;
    const int& getExecGrade(void) const;

    void beSigned(const Bureaucrat& bc);
    virtual void execute(Bureaucrat const & executor) = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char* what(void) const throw(); 
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what(void) const throw(); 
    };

    class NotSignedException : public std::exception {
    public:
        const char* what(void) const throw(); 
    };

    class NotExecuteException : public std::exception {
    public:
        const char* what(void) const throw(); 
    };
};

std::ostream& operator<<(std::ostream& o, const AForm& form);

#endif