#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int int_val)
{
    std::cout << "Int constructor called" << std::endl;
    fixed_point_value = int_val << fractional_bits;
}

Fixed::Fixed(const float float_val)
{
    std::cout << "Float constructor called" << std::endl;
    fixed_point_value = roundf(float_val * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        fixed_point_value = rhs.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)fixed_point_value / (1 << fractional_bits);
}

int Fixed::toInt(void) const
{
    return fixed_point_value >> fractional_bits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &f)
{
    out << f.toFloat();
    return out;
}
