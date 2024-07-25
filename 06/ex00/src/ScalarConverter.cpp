#include "ScalarConverter.hpp"
#include <sstream>
#include <iomanip>
#include <limits>

static void ToChar(double number)
{
    std::cout << "char: ";
    if (number != number || number > std::numeric_limits<char>::max() || number < std::numeric_limits<char>::min())
        std::cout << "impossible" << std::endl;
    else if (number == number && std::isprint(number))
        std::cout << "'" << static_cast<char>(number) << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

static void ToInt(double number)
{
    std::cout << "int: ";
    if (number != number || number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(number) << std::endl;
}

static void ToFloat(double number)
{
    std::cout << "float: ";
    if (number == std::numeric_limits<float>::infinity() || number == -std::numeric_limits<float>::infinity())
        std::cout << (number < 0 ? "-" : "") << "inff" << std::endl;
    else if (number != number)
        std::cout << "nanf" << std::endl;
    // else if (number >= std::numeric_limits<float>::max() || number <= std::numeric_limits<float>::min())
    //     std::cout << "impossible" << std::endl;
    else
    {
        if (static_cast<float>(number) - static_cast<int>(number) == 0.0)
            std::cout << static_cast<float>(number) << ".0f" << std::endl;
        else
            std::cout << static_cast<float>(number) << "f" << std::endl;
    }
}

static void ToDouble(double number)
{
    std::cout << "double: ";
    if (number == std::numeric_limits<double>::infinity() || number == -std::numeric_limits<double>::infinity())
        std::cout << (number < 0 ? "-" : "") << "inf" << std::endl;
    else if (number != number)
        std::cout << "nan" << std::endl;
    // else if (number >= std::numeric_limits<double>::max() || number <= std::numeric_limits<double>::min())
    //     std::cout << "impossible" << std::endl;
    else
    {
        if (number - static_cast<int>(number) == 0.0)
            std::cout << number << ".0" << std::endl;
        else
            std::cout << number << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    double number = 0.0;

    if (literal == "nan" || literal == "nanf")
        number = std::numeric_limits<double>::quiet_NaN();
    else if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff")
        number = std::numeric_limits<double>::infinity();
    else if (literal == "-inf" || literal == "-inff")
        number = -std::numeric_limits<double>::infinity();
    else
    {
        if (literal.size() == 1 && !std::isdigit(literal[0]))
            number = static_cast<double>(literal[0]);
        else
        {
            size_t i = 0;
            bool isFloat = false;

            if (literal[i] == '-' || literal[i] == '+')
                i++;
            while (literal[i])
            {
                if (literal[i] == '.')
                {
                    if (isFloat)
                        break;
                    isFloat = true;
                    i++;
                }
                if (!std::isdigit(literal[i]))
                    break;
                i++;
            }
            if (literal[i] == 'f' && !literal[i + 1])
                i++;
            if (i != literal.size())
            {
                std::cout << "char: impossible" << std::endl
                          << "int: impossible" << std::endl
                          << "float: impossible" << std::endl
                          << "double: impossible" << std::endl;
                return;
            }
        }

        std::stringstream ss(literal);
        ss >> number;
    }
    ToChar(number);
    ToInt(number);
    ToFloat(number);
    ToDouble(number);
}
