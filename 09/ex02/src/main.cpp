#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "Error: Usage: " << argv[0] << " <positive integer> ..." << std::endl;
		return EXIT_FAILURE;
	}

	PmergeMe pm(argc, argv);

	std::cout << "Before:  ";
	for (int i = 0; i < argc - 1 && i < 10; ++i)
		std::cout << pm.vec[i] << " ";
	if (argc - 1 > 10)
		std::cout << "...";
	std::cout << std::endl;

	clock_t start_time = clock();
	std::vector<int> res_vec = pm.merge_insertion_sort_vec(pm.vec);
	clock_t end_time = clock();

	std::cout << "After:   ";
	for (int i = 0; i < argc - 1 && i < 10; ++i)
		std::cout << res_vec[i] << " ";
	if (argc - 1 > 10)
		std::cout << "...";
	std::cout << std::endl;

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : "
			  << (end_time - start_time) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;

	start_time = clock();
	std::deque<int> res_deq = pm.merge_insertion_sort_deq(pm.deq);
	end_time = clock();

	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : "
			  << (end_time - start_time) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;

	bool is_sorted = true;
	for (int i = 0; i < argc - 2; ++i)
		if (res_vec[i] > res_vec[i + 1] || res_deq[i] > res_deq[i + 1])
		{
			is_sorted = false;
			break;
		}

	if (is_sorted)
		std::cout << "\033[1;32m" << "Success: The container is sorted." << "\033[0m" << std::endl;
	else
		std::cout << "\033[1;31m" << "Error: The container is not sorted." << "\033[0m" << std::endl;
	
	return EXIT_SUCCESS;
}
