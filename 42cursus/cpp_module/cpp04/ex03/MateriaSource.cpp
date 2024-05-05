#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	for(int i = 0; i < 4; i++){
		this->_memory[i] = 0;
	}
	std::cout << "MateriaSource Default constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource& obj){
	for(int i = 0; i < 4; i++){
		if (obj._memory[i])
			this->_memory[i] = obj._memory[i]->clone();
	}
	std::cout << "MateriaSource copy constructor called\n";
}

MateriaSource& MateriaSource::operator= (const MateriaSource& obj){
	if (this != &obj){
		for(int i = 0; i < 4; i++){
			if (this->_memory[i])
				delete this->_memory[i];
			if (obj._memory[i])
				this->_memory[i] = obj._memory[i]->clone();
		}
	}
	std::cout << "MateriaSource operator = called\n";
	return *this;
}

MateriaSource::~MateriaSource(void) {
	for(int i = 0; i < 4; i++){
		if (this->_memory[i])
			delete this->_memory[i];
	}
	std::cout << "MateriaSource destructor called\n";
}

void MateriaSource::learnMateria(AMateria *m){
	if (!m){
		std::cout << "This source doesn't have memory\n";
		return;
	}
	int idx = 0;
	while (this->_memory[idx] != 0 && idx < 4)
		idx++;
	if (idx == 4){
		std::cout << "This source\'s memory is full\n";
		return;
	}
	this->_memory[idx] = m;
	std::cout << "This source learns materia type " << m->getType() << " in slot\n";
}

AMateria* MateriaSource::createMateria(std::string const &type){
	int idx = 0;
	while (idx < 4 && this->_memory[idx] && (this->_memory[idx]->getType() != type))
		idx++;
	if (idx == 4 || !(this->_memory[idx])){
		std::cout << type << " materia does not exit\n";
		return NULL;
	}
	std::cout << "Materia " << type << " created\n";
	return this->_memory[idx]->clone();
}