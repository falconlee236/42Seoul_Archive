#include "Zombie.hpp"

int main(void){
    std::string name1 = "Kim", name2 = "Lee";
    Zombie* oneZombie = newZombie(name1);
    Zombie* twoZombie = newZombie(name2);
    oneZombie->announce();
    twoZombie->announce();
    delete oneZombie;
    delete twoZombie;
    randomChump(name1);
    randomChump(name1);
    return 0;
}