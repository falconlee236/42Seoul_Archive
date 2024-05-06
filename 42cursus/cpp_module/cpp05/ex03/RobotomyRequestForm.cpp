#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy_form", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm(target, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
    return *(dynamic_cast<RobotomyRequestForm *>(&(AForm::operator=(obj))));
	// 부모 클래스의 복사생성자의 결과를 자식 클래스 포인터 결과로 반환
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor){
	if (!this->getIsSign())
		throw NotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw NotExecuteException();
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << getName() << " has been robotomized successfully\n";
	else
		std::cout << getName() << " has been failed robotomized\n";
}

AForm *RobotomyRequestForm::clone(const std::string &target){
	return new RobotomyRequestForm(target);
}