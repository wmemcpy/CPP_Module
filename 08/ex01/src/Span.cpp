#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

Span::Span(unsigned int N) : max_size(N) {}

void Span::addNumber(int number)
{
    if (numbers.size() >= max_size)
        throw std::length_error("Span is full");
    numbers.push_back(number);
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw std::length_error("Not enough numbers in Span");

    std::sort(numbers.begin(), numbers.end());

    int min_span = std::numeric_limits<int>::max();
    for (size_t i = 0; i < numbers.size() - 1; ++i)
    {
        int span = numbers[i + 1] - numbers[i];
        if (span < min_span)
            min_span = span;
    }

    return min_span;
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw std::length_error("Not enough numbers in Span");

    std::sort(numbers.begin(), numbers.end());

    return numbers[numbers.size() - 1] - numbers[0];
}
