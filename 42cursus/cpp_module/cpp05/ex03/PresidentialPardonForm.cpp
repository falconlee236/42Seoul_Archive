#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("presidential_form", 72, 45) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm(target, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
    return *(dynamic_cast<PresidentialPardonForm *>(&(AForm::operator=(obj))));
	// 부모 클래스의 복사생성자의 결과를 자식 클래스 포인터 결과로 반환
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(Bureaucrat const & executor){
	if (!this->getIsSign())
		throw NotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw NotExecuteException();
	std::cout << this->getName() << " has been pardon by Zaphod Beeblebrox\n";
}

AForm *PresidentialPardonForm::clone(const std::string &target){
	return new PresidentialPardonForm(target);
}