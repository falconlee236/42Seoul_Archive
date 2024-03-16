#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name){
    Zombie* zombies = new Zombie[N];
    zombies[0].set_name(name);
    zombies[0].announce();
    for(int i = 1; i < N; i++){
        std::stringstream ss;
        ss << i;
        std::string str;
        ss >> str;
        zombies[i].set_name(str);
        zombies[i].announce();
        ss.str("");
        ss.clear();
    }
    return zombies;
}