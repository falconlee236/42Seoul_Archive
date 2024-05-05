#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void leak_check(void){
    system("leaks ex03");
}

int main(){
    atexit(&leak_check);
    IMateriaSource *src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter *me = new Character("me");


    AMateria *tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("fire"); // null
	me->equip(tmp);
    std::cout << std::endl;


    ICharacter *bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    me->use(2, *bob);
	me->use(-4, *bob);
	me->use(18, *bob);
	std::cout << std::endl;


    delete bob;
    delete me;
    delete src;
    return 0;
}