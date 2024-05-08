#include "iter.hpp"

int main(void){
    int tab[4] = {1, 2, 3, 4};
    iter(tab, 4, print);
    std::string ts[3] = {
        "hello",
        "world",
        "nice to meet you"};
    iter(ts, 3, print);
}