#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iostream>
#include <algorithm>

// T는 container ex) vector<int>
template <typename T>
typename T::iterator easyfind(T &container, int target){
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end()){
        throw std::runtime_error("value find failed");
    }
    return it;
}

#endif