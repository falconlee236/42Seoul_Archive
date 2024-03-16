#include "Zombie.hpp"

int main(void){
    Zombie* zombies = zombieHorde(10, "Kim");
    delete[] zombies;
    zombies = zombieHorde(10, "Lee");
    delete[] zombies;
}