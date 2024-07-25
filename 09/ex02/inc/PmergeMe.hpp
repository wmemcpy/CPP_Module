#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <deque>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(int argc, char *argv[]);
	PmergeMe(const PmergeMe &other);
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);

	std::vector<int> vec;
	std::deque<int> deq;

	const std::vector<int> merge_insertion_sort_vec(const std::vector<int> &vec);
	const std::deque<int> merge_insertion_sort_deq(const std::deque<int> &deq);
};
