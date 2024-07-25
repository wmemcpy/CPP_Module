#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <cstdlib>

PmergeMe::PmergeMe()
{
	srand(time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		int num = rand() % 100 + 1;
		vec.push_back(num);
		deq.push_back(num);
	}
}

PmergeMe::PmergeMe(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		int num;
		if (!(iss >> num) || num <= 0)
		{
			std::cout << "Error: Invalid input \"" << argv[i] << "\" is not a positive integer." << std::endl;
			exit(1);
		}
		vec.push_back(num);
		deq.push_back(num);
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		vec = other.vec;
		deq = other.deq;
	}
	return *this;
}

/* ******************* VECTOR ******************* */

static void binary_search_vec(std::vector<int> &sorted_list, int item)
{
	int left = 0;
	int right = sorted_list.size() - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (left == right)
		{
			if (sorted_list[middle] < item)
				left = middle + 1;
			break;
		}
		else if (sorted_list[middle] < item)
			left = middle + 1;
		else
			right = middle - 1;
	}
	sorted_list.insert(sorted_list.begin() + left, item);
}

static std::vector<std::vector<int> > merge_vec(const std::vector<std::vector<int> > &left, const std::vector<std::vector<int> > &right)
{
	std::vector<std::vector<int> > result;
	std::size_t leftIndex = 0, rightIndex = 0;
	while (leftIndex < left.size() && rightIndex < right.size())
	{
		if (left[leftIndex][0] < right[rightIndex][0])
			result.push_back(left[leftIndex++]);
		else
			result.push_back(right[rightIndex++]);
	}
	while (leftIndex < left.size())
		result.push_back(left[leftIndex++]);
	while (rightIndex < right.size())
		result.push_back(right[rightIndex++]);
	return result;
}

static std::vector<std::vector<int> > sortlist_vec(const std::vector<std::vector<int> > &vec)
{
	int length = vec.size();
	if (length <= 1)
		return vec;
	int middle = length / 2;
	std::vector<std::vector<int> > left(vec.begin(), vec.begin() + middle);
	std::vector<std::vector<int> > right(vec.begin() + middle, vec.end());
	return merge_vec(sortlist_vec(left), sortlist_vec(right));
}

const std::vector<int> PmergeMe::merge_insertion_sort_vec(const std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return vec;

	std::vector<std::vector<int> > two_paired_list;
	bool has_last_odd_item = false;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (i == vec.size() - 1)
			has_last_odd_item = true;
		else
		{
			std::vector<int> pair(2);
			if (vec[i] < vec[i + 1])
			{
				pair[0] = vec[i];
				pair[1] = vec[i + 1];
			}
			else
			{
				pair[0] = vec[i + 1];
				pair[1] = vec[i];
			}
			two_paired_list.push_back(pair);
		}
	}

	std::vector<std::vector<int> > sorted_vec = sortlist_vec(two_paired_list);

	std::vector<int> result;
	for (size_t i = 0; i < sorted_vec.size(); ++i)
		result.push_back(sorted_vec[i][0]);

	result.push_back(sorted_vec.back()[1]);

	if (has_last_odd_item)
	{
		int pivot = vec.back();
		binary_search_vec(result, pivot);
	}

	bool has_odd = false;
	for (size_t i = 0; i < sorted_vec.size() - 1; ++i)
	{
		if (result[i] == vec.back() && has_last_odd_item)
			has_odd = true;
		int pivot = sorted_vec[i][1];
		if (has_odd)
		{
			std::vector<int> temp(result.begin() + i + 2, result.end());
			binary_search_vec(temp, pivot);
			result = std::vector<int>(result.begin(), result.begin() + i + 2);
			result.insert(result.end(), temp.begin(), temp.end());
		}
		else
		{
			std::vector<int> temp(result.begin() + i + 1, result.end());
			binary_search_vec(temp, pivot);
			result = std::vector<int>(result.begin(), result.begin() + i + 1);
			result.insert(result.end(), temp.begin(), temp.end());
		}
	}

	return result;
}

/* ******************* DEQUE ******************* */

static void binary_search_deq(std::deque<int> &sorted_list, int item)
{
    int left = 0;
    int right = sorted_list.size() - 1;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (left == right)
        {
            if (sorted_list[middle] < item)
                left = middle + 1;
            break;
        }
        else if (sorted_list[middle] < item)
            left = middle + 1;
        else
            right = middle - 1;
    }
    sorted_list.insert(sorted_list.begin() + left, item);
}

static std::deque<std::deque<int> > merge_deq(const std::deque<std::deque<int> > &left, const std::deque<std::deque<int> > &right)
{
    std::deque<std::deque<int> > result;
    std::size_t leftIndex = 0, rightIndex = 0;
    while (leftIndex < left.size() && rightIndex < right.size())
    {
        if (left[leftIndex][0] < right[rightIndex][0])
            result.push_back(left[leftIndex++]);
        else
            result.push_back(right[rightIndex++]);
    }
    while (leftIndex < left.size())
        result.push_back(left[leftIndex++]);
    while (rightIndex < right.size())
        result.push_back(right[rightIndex++]);
    return result;
}

static std::deque<std::deque<int> > sortlist_deq(const std::deque<std::deque<int> > &deq)
{
    int length = deq.size();
    if (length <= 1)
        return deq;
    int middle = length / 2;
    std::deque<std::deque<int> > left(deq.begin(), deq.begin() + middle);
    std::deque<std::deque<int> > right(deq.begin() + middle, deq.end());
    return merge_deq(sortlist_deq(left), sortlist_deq(right));
}

const std::deque<int> PmergeMe::merge_insertion_sort_deq(const std::deque<int> &deq)
{
    if (deq.size() <= 1)
        return deq;

    std::deque<std::deque<int> > two_paired_list;
    bool has_last_odd_item = false;
    for (size_t i = 0; i < deq.size(); i += 2)
    {
        if (i == deq.size() - 1)
            has_last_odd_item = true;
        else
        {
            std::deque<int> pair(2);
            if (deq[i] < deq[i + 1])
            {
                pair[0] = deq[i];
                pair[1] = deq[i + 1];
            }
            else
            {
                pair[0] = deq[i + 1];
                pair[1] = deq[i];
            }
            two_paired_list.push_back(pair);
        }
    }

    std::deque<std::deque<int> > sorted_deq = sortlist_deq(two_paired_list);

    std::deque<int> result;
    for (size_t i = 0; i < sorted_deq.size(); ++i)
        result.push_back(sorted_deq[i][0]);

    result.push_back(sorted_deq.back()[1]);

    if (has_last_odd_item)
    {
        int pivot = deq.back();
        binary_search_deq(result, pivot);
    }

    bool has_odd = false;
    for (size_t i = 0; i < sorted_deq.size() - 1; ++i)
    {
        if (result[i] == deq.back() && has_last_odd_item)
            has_odd = true;
        int pivot = sorted_deq[i][1];
        if (has_odd)
        {
            std::deque<int> temp(result.begin() + i + 2, result.end());
            binary_search_deq(temp, pivot);
            result = std::deque<int>(result.begin(), result.begin() + i + 2);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        else
        {
            std::deque<int> temp(result.begin() + i + 1, result.end());
            binary_search_deq(temp, pivot);
            result = std::deque<int>(result.begin(), result.begin() + i + 1);
            result.insert(result.end(), temp.begin(), temp.end());
        }
    }

    return result;
}
