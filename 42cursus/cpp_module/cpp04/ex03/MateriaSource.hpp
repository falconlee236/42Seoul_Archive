#ifndef __MATERIASOURCE_HPP__
#define __MATERIASOURCE_HPP__

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria* _memory[4];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& obj);
	MateriaSource& operator= (const MateriaSource& obj);
    ~MateriaSource(void);
    void learnMateria(AMateria *m);
    AMateria *createMateria(std::string const &type);
};
#endif