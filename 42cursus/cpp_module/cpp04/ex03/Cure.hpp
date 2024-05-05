#ifndef __CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria{
public:
    Cure(void);
    Cure(const Cure& obj);
    Cure& operator= (const Cure& obj);
    ~Cure(void);
    Cure* clone() const;
    void use(ICharacter& target);
};
#endif