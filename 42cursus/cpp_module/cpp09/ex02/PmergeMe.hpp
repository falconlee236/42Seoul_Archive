#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

typedef std::vector<std::pair<std::vector<int>, std::vector<int> > > pair_vec_type;

std::vector<int> ford_johnson_vector(std::vector<int> &arr);


#endif
