#include "Brain.hpp"

Brain::Brain(void){
	for (int i = 0; i < 100; i++){
		this->ideas[i] = "";
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