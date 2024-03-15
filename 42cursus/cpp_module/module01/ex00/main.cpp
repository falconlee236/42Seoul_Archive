#include "Zombie.hpp"

int main(void){
    Zombie oneZombie("stack");
    Zombie* twoZombie = newZombie("heap");
    oneZombie.announce();
    twoZombie->announce();
    delete twoZombie;
    return 0;
}