#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "-----[test p1 int]-----" << std::endl;

    Array<int> intArray;
    std::cout << "Size of default constructed intArray: " << intArray.size() << std::endl;

    Array<int> sizedArray(5);
    std::cout << "Size of sizedArray: " << sizedArray.size() << std::endl;

    for (unsigned int i = 0; i < sizedArray.size(); ++i)
    {
        sizedArray[i] = i * 2;
        std::cout << "sizedArray[" << i << "] = " << sizedArray[i] << std::endl;
    }

    Array<int> copiedArray = sizedArray;
    std::cout << "Size of copiedArray: " << copiedArray.size() << std::endl;
    for (unsigned int i = 0; i < copiedArray.size(); ++i)
        std::cout << "copiedArray[" << i << "] = " << copiedArray[i] << std::endl;

    sizedArray[0] = 100;
    std::cout << "After modification, sizedArray[0] = " << sizedArray[0] << std::endl;
    std::cout << "After modification, copiedArray[0] = " << copiedArray[0] << std::endl;

    try
    {
        std::cout << "Trying to access out-of-bounds element" << std::endl;
        sizedArray[10] = 20;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "-----[test p2 std::string]-----" << std::endl;

    Array<std::string> stringArray(3);
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "!";
    for (unsigned int i = 0; i < stringArray.size(); ++i)
        std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;
 
    return 0;
}
