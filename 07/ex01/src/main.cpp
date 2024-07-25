#include "iter.hpp"
#include <iostream>

void multiplyByTwo(const int &elem)
{
    std::cout << elem * 2 << std::endl;
}

int main()
{
    std::cout << "----- [int array test 1] -----" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, multiplyByTwo);

    std::cout << "----- [string array test 2] -----" << std::endl;
    std::string strArray[] = {"one", "two", "three"};
    iter(strArray, 3, printElement);

    return 0;
}
