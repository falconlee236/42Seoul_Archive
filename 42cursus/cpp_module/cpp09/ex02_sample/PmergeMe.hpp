#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <string>
#include <sstream>

#define MAX_LENGTH 10
#define MAX_INTEGER "2147483647"

// COLORS
#define PURPLE "\033[1;35m"
#define RESET "\033[0;37m"
#define CYAN "\033[1;36m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"

typedef std::vector<int> int_vect;
typedef std::vector<std::pair<int_vect, int_vect> > int_vect_pair;
typedef std::deque<int> int_deque;
typedef std::deque<std::pair<int_deque, int_deque> > deque_pair;

class PmergeMe
{
private:
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);
	~PmergeMe();

	// PARSING MATHODS
	static bool positive_integer(std::string);
	static bool value_max(const char *, size_t);
	static bool only_digits(std::string);

public:
	static bool numbers_valid(char **);
	static void get_values(char **, int_vect &, int_deque &);

	// START
	static void start_sorting_vect(int_vect &);
	static void start_sorting_deque(int_deque &);

	// SORTING METHODS FOR VECTOR
	static void merge_insertion_vect(int_vect &, size_t, size_t);
	static void create_pairs_for_vect(int_vect &, int_vect_pair &, size_t, size_t);
	static void merge_and_update_vect(int_vect &, int_vect_pair &);
	static void insertion_vect(int_vect &, size_t, size_t);

	// SORTING METHODS FOR DEQUE
	static void merge_insertion_deque(int_deque &, size_t, size_t);
	static void create_pairs_for_deque(int_deque &, deque_pair &, size_t, size_t);
	static void merge_and_update_deque(int_deque &, deque_pair &);
	static void insertion_deque(int_deque &, size_t, size_t);

	// EXIT METHOD
	static int err_exit(int exit_status);

	// PRINTING MATHODS
	static void print_vect(const char *, const char *, int_vect &);
	static void print_vect_of_pairs(int_vect_pair);
	static void print_vect_of_vect(std::vector<int_vect>);
	static void print_deque(const char *, const char *, int_deque &);
	static void print_time(clock_t, clock_t, size_t, const char *);
};

#endif