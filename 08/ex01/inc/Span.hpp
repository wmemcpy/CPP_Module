#pragma once

#include <vector>
#include <exception>

class Span
{
public:
    Span(unsigned int N);
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

private:
    std::vector<int> numbers;
    unsigned int max_size;
};
