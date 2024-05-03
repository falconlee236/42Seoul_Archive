#include "Brain.hpp"

Brain::Brain(void){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = 'A' + (i % 26);
	}
	std::cout << "Brain default constructor called\n";
}
Brain::Brain(const Brain& obj){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = obj.ideas[i];
	}
	std::cout << "Brain copy constructor called\n";
}
Brain& Brain::operator= (const Brain& obj){
	if (this != &obj){
		for (int i = 0; i < 100; i++){
			this->ideas[i] = obj.ideas[i];
		}	
	}
	std::cout << "Brain operator = called\n";
	return *this;
}
Brain::~Brain(void){
	std::cout << "Brain destructor called\n";
}

const std::string* Brain::getIdeas(void) const{
    return ideas;
}

void Brain::setIdeas(std::string idea){
    if (idea.empty())
        idea = "zzzzzzz...zzzzzzz";
    for (int i = 0; i < 100; i++)
        ideas[i] = idea;
}