#include "PmergeMe.hpp"

bool PmergeMe::value_max(const char *str, size_t len)
{
	// 숫자가 MAX_INTEGER보다 크면 true
	if (str[0] == '+')
	{
		len--;
		str++;
	}
	// 2147483647
	if (len > MAX_LENGTH)
		return true;
	else if (len < MAX_LENGTH)
		return false;
	else
	{
		int i = 0;
		while (str[i])
		{
			if (str[i] == MAX_INTEGER[i])
			{
				i++;
				continue;
			}
			return (str[i] > MAX_INTEGER[i]);
		}
	}
	return false;
}

bool PmergeMe::only_digits(std::string str)
{
	int i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return false;
		i++;
	}
	return true;
}

bool PmergeMe::positive_integer(std::string str)
{
	if (!only_digits(str) || value_max(str.c_str(), str.length()))
		return false;
	return true;
}

bool PmergeMe::numbers_valid(char **av)
{
	int i = 1;
	while (av[i])
	{
		if (!positive_integer(std::string(av[i])))
			return false;
		i++;
	}
	return true;
}
// #parse the input values and store them in the vectors

void PmergeMe::get_values(char **av, int_vect &vect_nums, int_deque &deque_nums)
{
	int i = 1;
	while (av[i])
	{
		int num;
		std::stringstream ss(av[i]);
		ss >> num;
		vect_nums.push_back(num);
		deque_nums.push_back(num);
		i++;
	}
}

int PmergeMe::err_exit(int exit_status)
{
	std::cout << "Error" << std::endl;
	exit(exit_status);
}

void PmergeMe::print_vect_of_vect(std::vector<int_vect> v)
{
	std::vector<int_vect>::iterator it;
	int_vect::iterator v_it;
	std::cout << "[ ";
	for (it = v.begin(); it != v.end(); it++)
	{
		std::cout << "{ ";
		print_vect(CYAN, "", *it);
		std::cout << " }";
		if (it != v.end() - 1)
			std::cout << ", ";
	}
}

void PmergeMe::print_vect(const char *color, const char *status, int_vect &vect)
{
	int_vect::iterator it;

	std::cout << color << status;
	for (it = vect.begin(); it != vect.end(); it++)
	{
		std::cout << *it;
		if (it != vect.end() - 1)
			std::cout << " ";
	}
	std::cout << RESET << std::endl;
}

void print_vec(const char *color, const char *status, int_vect &vect)
{
	int_vect::iterator it;

	std::cout << color << status;
	for (it = vect.begin(); it != vect.end(); it++)
	{
		std::cout << *it;
		if (it != vect.end() - 1)
			std::cout << " ";
	}
}

void PmergeMe::print_vect_of_pairs(int_vect_pair vect)
{
	int_vect_pair::iterator it;
	std::cout << "{ ";
	for (it = vect.begin(); it != vect.end(); it++)
	{
		std::cout << RED "(" RESET;
		print_vec(GREEN, "", (*it).first);
		std::cout << RESET " ,";
		print_vec(GREEN, "", (*it).second);
		std::cout << RED ")" RESET;
		if (it != vect.end() - 1)
			std::cout << " ";
	}
	std::cout << RESET << " }" << std::endl;
}

void PmergeMe::print_deque(const char *color, const char *status, int_deque &deq)
{
	int_deque::iterator it;

	std::cout << color << status;
	for (it = deq.begin(); it != deq.end(); it++)
	{
		std::cout << *it;
		if (it != deq.end() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::print_time(clock_t start, clock_t end, size_t container_size, const char *type)
{
	double time_taken = (double(end - start) * 1000) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << RED << container_size << RESET << " elements with " << RED << type << RESET << " : ";
	std::cout << GREEN << time_taken << RESET << " us" << std::endl;
}

// Ford-Johnson Algorithm for Vectors

// args: numbers, v, len, pairLen
// numbers: 인트 벡터
// v: 인트 페어 벡터
// len: 벡터의 길이
// pairLen: 벡트 페어의 길이
void PmergeMe::create_pairs_for_vect(int_vect &numbers, int_vect_pair &v, size_t len, size_t pairLen)
{
	size_t index = 0;
	size_t pairsLeftToCreate;

	if (len / pairLen % 2)
		pairsLeftToCreate = len / pairLen - 1;
	else
		pairsLeftToCreate = len / pairLen;

	while (pairsLeftToCreate)
	{
		int_vect v1, v2;
		while (v1.size() != pairLen)
			v1.push_back(numbers[index++]);
		while (v2.size() != pairLen)
			v2.push_back(numbers[index++]);
		v.push_back(make_pair(v1, v2));
		pairsLeftToCreate -= 2;
	}
	print_vect_of_pairs(v); // _debug_module
}

void PmergeMe::merge_and_update_vect(int_vect &numbers, int_vect_pair &v)
{
	int_vect_pair::iterator it;
	int_vect::iterator v_it;
	size_t index = 0;

	for (it = v.begin(); it != v.end(); it++)
	{
		if (it->first.back() > it->second.back())
		{
			std::cout << "======================" << std::endl; // _debug_module
			for (v_it = it->second.begin(); v_it != it->second.end(); v_it++)
			{
				std::cout << "v_it1: " << *v_it << std::endl; // _debug_module
				numbers[index++] = *v_it;
			}
			for (v_it = it->first.begin(); v_it != it->first.end(); v_it++)
			{
				std::cout << "v_it2: " << *v_it << std::endl; // _debug_module
				numbers[index++] = *v_it;
			}
		}
		else
			index += (it->first.size() * 2);
	}
	print_vect(CYAN, "After merge: ", numbers);						// _debug_module
	std::cout << "==================================" << std::endl; // _debug_module
}

size_t binary_search_insert_vect(const int_vect &numbers, int value, size_t start, size_t end)
{
	// lower_bound는 value보다 크거나 같은 첫번째 원소의 위치를 반환
	int_vect::const_iterator lower = std::lower_bound(numbers.begin() + start, numbers.begin() + end, value);
	return static_cast<size_t>(lower - numbers.begin());
}

void PmergeMe::insertion_vect(int_vect &numbers, size_t len, size_t pairLen)
{
	for (size_t i = pairLen; i < len; i++)
	{
		int current = numbers[i];
		size_t j = i - 1;
		size_t insertionPoint = binary_search_insert_vect(numbers, current, 0, i);

		while (j >= insertionPoint && j < i)
		{
			numbers[j + 1] = numbers[j];
			if (j == 0)
				break;
			j--;
		}
		numbers[insertionPoint] = current;
		print_vect(CYAN, "Before insertion: ", numbers); // _debug_module

	}
}

void PmergeMe::merge_insertion_vect(int_vect &numbers, size_t len, size_t pairLen)
{
	int_vect_pair v;
	size_t newSize;
	if (len / pairLen % 2)
		newSize = len - pairLen;
	else
		newSize = len;
	if (pairLen == len)
		return;
	create_pairs_for_vect(numbers, v, len, pairLen);
	merge_and_update_vect(numbers, v);
	merge_insertion_vect(numbers, newSize, pairLen * 2);
	insertion_vect(numbers, len, pairLen);
}

void PmergeMe::start_sorting_vect(int_vect &numbers)
{
	merge_insertion_vect(numbers, numbers.size(), 1);
}

// Ford-Johnson Algorithm for Deques

size_t binary_search_insert_deque(const int_deque &numbers, int value, size_t start, size_t end)
{
	int_deque::const_iterator lower = std::lower_bound(numbers.begin() + start, numbers.begin() + end, value);
	return static_cast<size_t>(lower - numbers.begin());
}

void PmergeMe::insertion_deque(int_deque &numbers, size_t len, size_t pairLen)
{
	for (size_t i = pairLen; i < len; i++)
	{
		int current = numbers[i];
		size_t j = i - 1;
		size_t insertionPoint = binary_search_insert_deque(numbers, current, 0, i);
		while (j >= insertionPoint && j < i)
		{
			numbers[j + 1] = numbers[j];
			if (j == 0)
			{
				break;
			}
			j--;
		}
		numbers[insertionPoint] = current;
	}
}

void PmergeMe::merge_and_update_deque(int_deque &numbers, deque_pair &v)
{
	deque_pair::iterator it;
	int_deque::iterator v_it;
	size_t index = 0;

	for (it = v.begin(); it != v.end(); it++)
	{
		if (it->first.back() > it->second.back())
		{
			for (v_it = it->second.begin(); v_it != it->second.end(); v_it++)
				numbers[index++] = *v_it;
			for (v_it = it->first.begin(); v_it != it->first.end(); v_it++)
				numbers[index++] = *v_it;
		}
		else
			index += (it->first.size() * 2);
	}
}

void PmergeMe::create_pairs_for_deque(int_deque &numbers, deque_pair &v, size_t len, size_t pairLen)
{
	size_t index = 0;
	size_t pairsLeftToCreate = (len / pairLen) % 2 ? len / pairLen - 1 : len / pairLen;
	while (pairsLeftToCreate)
	{
		int_deque v1, v2;
		while (v1.size() != pairLen)
			v1.push_back(numbers[index++]);
		while (v2.size() != pairLen)
			v2.push_back(numbers[index++]);
		v.push_back(make_pair(v1, v2));
		pairsLeftToCreate -= 2;
	}
}

void PmergeMe::merge_insertion_deque(int_deque &numbers, size_t len, size_t pairLen)
{
	deque_pair v;
	size_t newSize = (len / pairLen) % 2 ? len - pairLen : len;

	if (pairLen == len)
		return;
	create_pairs_for_deque(numbers, v, len, pairLen);
	merge_and_update_deque(numbers, v);
	merge_insertion_deque(numbers, newSize, pairLen * 2);
	insertion_deque(numbers, len, pairLen);
}

void PmergeMe::start_sorting_deque(int_deque &numbers)
{
	merge_insertion_deque(numbers, numbers.size(), 1);
}