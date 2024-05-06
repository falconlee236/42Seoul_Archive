#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery_form", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm(target, 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj){
    return *(dynamic_cast<ShrubberyCreationForm *>(&(AForm::operator=(obj))));
	// 부모 클래스의 복사생성자의 결과를 자식 클래스 포인터 결과로 반환
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor){
	if (!this->getIsSign())
		throw NotSignedException();
	if (this->getExecGrade() < executor.getGrade())
		throw NotExecuteException();

	std::ofstream fstream(this->getName() + "_shrubbery");
	if (!fstream.is_open())
		throw NotExecuteException();

	std::string tree = 
		"													 |\n\
													-x-\n\
													 |\n\
					v .   ._, |_  .,\n\
				`-._\\/  .  \\ /    |/_\n\
					\\  _\\, y | \\//\n\
				_\\_.___\\, \\/ -.\\||\n\
				`7-,--.`._||  / / ,\n\
				/'     `-. `./ / |/_.'\n\
							|    |//\n\
							|_    /\n\
							|-   |\n\
							|   =|\n\
							|    |\n\
		--------------------/ ,  . \\--------._";
	fstream << tree;
	fstream.close();
	std::cout << "Shrubbery tree making success\n";
}