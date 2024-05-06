#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include "AForm.hpp"

class Intern {
public:
    Intern(void);
    Intern(const Intern& obj);
    Intern& operator= (const Intern& obj);
    ~Intern(void);

    AForm* makeForm(const std::string& name, const std::string& target);

    class FormNameError : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif