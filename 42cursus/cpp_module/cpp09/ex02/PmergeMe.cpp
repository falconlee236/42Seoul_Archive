#include "PmergeMe.hpp"

static void insert_arr_use_vec(int_vec &arr, size_t size, size_t pair_size){
	for(size_t i = pair_size; i < size; i++){
		int target = arr[i];
		int_vec::iterator it = std::lower_bound(arr.begin(), arr.begin() + i, target);
		size_t insert_point = it - arr.begin();
		for(size_t j = i - 1; j >= insert_point && j < i; j--){
			arr[j + 1] = arr[j];
			if (j == 0) break;
		}
		arr[insert_point] = target;
	}
}

static void update_arr_use_vec(int_vec_pair_vec& pairs, int_vec &arr){
	for(size_t i = 0, idx = 0; i < pairs.size(); i++){
		if (pairs[i].first.back() > pairs[i].second.back()){
			for(size_t j = 0; j < pairs[i].second.size(); j++)
				arr[idx++] = pairs[i].second[j];
			for(size_t j = 0; j < pairs[i].first.size(); j++)
				arr[idx++] = pairs[i].first[j];
		} else idx += pairs[i].first.size();
	}
}

static void create_pairs_use_vec(int_vec_pair_vec &pairs, int_vec &arr, size_t size, size_t pair_size){
	size_t idx = 0;
	size_t cnt = (size / pair_size) % 2 ? size / pair_size - 1 : size / pair_size;

	for(size_t i = 0; i < cnt; i+=2){
		int_vec left, right;
		while (left.size() != pair_size)
			left.push_back(arr[idx++]);
		while (right.size() != pair_size)
			right.push_back(arr[idx++]);
		pairs.push_back(make_pair(left, right));
	}
}

static void merge_insertion_use_vec(int_vec &arr, size_t size, size_t pair_size){
	if (pair_size == size)
		return;
	
	int_vec_pair_vec pairs;
	size_t merge_size = (size / pair_size) % 2 ? size - pair_size : size;

	create_pairs_use_vec(pairs, arr, size, pair_size);
	update_arr_use_vec(pairs, arr);
	merge_insertion_use_vec(arr, merge_size, pair_size * 2);
	insert_arr_use_vec(arr, size, pair_size);
}

void sorting_use_vector(int_vec &arr){
	merge_insertion_use_vec(arr, arr.size(), 1);
}

static void insert_arr_use_deq(int_deq &arr, size_t size, size_t pair_size){
	for(size_t i = pair_size; i < size; i++){
		int target = arr[i];
		int_deq::iterator it = std::lower_bound(arr.begin(), arr.begin() + i, target);
		size_t insert_point = it - arr.begin();
		for(size_t j = i - 1; j >= insert_point && j < i; j--){
			arr[j + 1] = arr[j];
			if (j == 0) break;
		}
		arr[insert_point] = target;
	}
}

static void update_arr_use_deq(int_deq_pair_deq& pairs, int_deq &arr){
	for(size_t i = 0, idx = 0; i < pairs.size(); i++){
		if (pairs[i].first.back() > pairs[i].second.back()){
			for(size_t j = 0; j < pairs[i].second.size(); j++)
				arr[idx++] = pairs[i].second[j];
			for(size_t j = 0; j < pairs[i].first.size(); j++)
				arr[idx++] = pairs[i].first[j];
		} else idx += pairs[i].first.size();
	}
}

static void create_pairs_use_deq(int_deq_pair_deq &pairs, int_deq &arr, size_t size, size_t pair_size){
	size_t idx = 0;
	size_t cnt = (size / pair_size) % 2 ? size / pair_size - 1 : size / pair_size;

	for(size_t i = 0; i < cnt; i+=2){
		int_deq left, right;
		while (left.size() != pair_size)
			left.push_back(arr[idx++]);
		while (right.size() != pair_size)
			right.push_back(arr[idx++]);
		pairs.push_back(make_pair(left, right));
	}
}

static void merge_insertion_use_deq(int_deq &arr, size_t size, size_t pair_size){
	if (pair_size == size)
		return;
	
	int_deq_pair_deq pairs;
	size_t merge_size = (size / pair_size) % 2 ? size - pair_size : size;

	create_pairs_use_deq(pairs, arr, size, pair_size);
	update_arr_use_deq(pairs, arr);
	merge_insertion_use_deq(arr, merge_size, pair_size * 2);
	insert_arr_use_deq(arr, size, pair_size);
}

void sorting_use_deque(int_deq &arr){
	merge_insertion_use_deq(arr, arr.size(), 1);
}

void print_time(clock_t start, clock_t end, size_t size, std::string type){
	double time_taken = (double(end - start) * 1000) / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << size << " elements with " << type << " : " << time_taken << " us" << "\n";
}