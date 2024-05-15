#include "easyfind.hpp"
#include <vector>
#include <queue>
#include <list>

int main(void){
    std::vector<int> v;
    std::deque<int> d;
    std::list<int> l;

    for (int i = 0; i < 10; i++){
        v.push_back(i);
        d.push_back(i);
        l.push_back(i);
    }

    try{
        std::cout << *(easyfind(v, 2)) << " is at " << std::distance(v.begin(), easyfind(v, 2)) << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << '\n';
    }
    try{
        std::cout << *(easyfind(d, 0)) << " is at " << std::distance(d.begin(), easyfind(d, 0)) << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << '\n';
    }
    try{
        std::cout << *(easyfind(l, 10)) << " is at " << std::distance(l.begin(), easyfind(l, 5)) << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << '\n';
    }
    return (0);
}