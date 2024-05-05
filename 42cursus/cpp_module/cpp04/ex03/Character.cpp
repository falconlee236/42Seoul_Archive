#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void){
	this->_name = "default";
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = 0;
	}
	std::cout << "Character " << this->getName() << " constructor called\n";
}

Character::Character(std::string name){
	this->_name = name;
	for(int i = 0; i < 4; i++){
		this->_inventory[i] = 0;
	}
	std::cout << "Character " << this->getName() << " constructor called\n";
}

Character::Character(const Character& obj){
	this->_name = obj.getName() + "_copy";
	// deep copy
	for(int i = 0; i < 4; i++){
		if ((obj._inventory)[i])
			(this->_inventory)[i] = (obj._inventory)[i]->clone();
	}
	std::cout << "Character " << this->getName() << " copy constructor called\n";
}

Character& Character::operator= (const Character& obj){
	if (this != &obj){
		for(int i = 0; i < 4; i++){
			if ((this->_inventory)[i])
				delete (this->_inventory)[i];
			if ((obj._inventory)[i])
				(this->_inventory)[i] = (obj._inventory)[i]->clone();
		}	
	}
	std::cout << "Character " << this->getName() << " operator = called\n";
	return *this;
}

Character::~Character(void){
	for(int i = 0; i < 4; i++){
		if (this->getInventory(i))
			delete this->_inventory[i];
	}
	std::cout << "Character " << this->getName() << " destructor called\n";
}

std::string const& Character::getName(void) const{
	return this->_name;
}

void Character::equip(AMateria *m){
	if (!m){
		std::cout << "This" << this->getName() << " character doesn't have inventory\n";
		return;
	}
	int idx = 0;
	while (this->_inventory[idx] != 0 && idx < 4)
		idx++;
	if (idx == 4){
		std::cout << "This" << this->getName() << " character's inventory is full\n";
		return;
	}
	this->_inventory[idx] = m;
	std::cout << "This" << this->getName() << " character equipped materia type " << m->getType() << "in slot " << idx << " \n";
}
void Character::unequip(int idx){
	if (idx < 0 || idx >= 4){
		std::cout << "index out of range\n";
		return;
	}
	if (!this->getInventory(idx)){
		std::cout << "This" << this->getName() << " character doesn't have Materia\n";
		return;
	}
	AMateria* dropped = this->getInventory(idx);
	this->_inventory[idx] = 0;
	std::cout << "This" << this->getName() << " character unequipped materia type " << dropped->getType() << "in slot " << idx << " \n";
}
void Character::use(int idx, ICharacter &target){
	if (idx < 0 || idx >= 4){
		std::cout << "index out of range\n";
		return;
	}
	if (!this->getInventory(idx)){
		std::cout << "This" << this->getName() << " character doesn't have Materia\n";
		return;
	}
	std::cout << "This " << this->getName() << "\n";
	(this->_inventory[idx])->use(target);
}
AMateria* Character::getInventory(int idx) const {
	return this->_inventory[idx];
}