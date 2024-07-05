#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

typedef std::vector<std::pair<std::vector<int>, std::vector<int> > > int_vec_pair_vec;
typedef std::vector<int> int_vec;

typedef std::deque<std::pair<std::deque<int>, std::deque<int> > > int_deq_pair_deq;
typedef std::deque<int> int_deq;

void sorting_use_vector(int_vec &arr);
void sorting_use_deque(int_deq &arr);

void print_time(clock_t start, clock_t end, size_t size, std::string type);

#endif
